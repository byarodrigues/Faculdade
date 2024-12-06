#!/usr/bin/python3 -u
# -*- coding: utf-8 -*-

'''
Algoritmos de busca
'''

import logging
from collections import namedtuple
from multiprocessing import Process, Queue
from random import shuffle

XIS = 'X'
BOL = 'O'

Estado = namedtuple('Estado', 'jogador, tabuleiro, jogadas')

class JogoVelha:
    '''Classe abstrata para jogos'''

    def __init__(self, metricas=(3, 3, 3), display=True, limite=None):
        largura, altura, sequencia = metricas
        self._largura = largura
        self._altura = altura
        self._sequencia = sequencia
        self._display = display
        self._limite = limite
        jogadas = [(col, lin) for col in range(1, largura + 1)
                   for lin in range(1, altura + 1)]
        self._inicial = Estado(jogador=XIS, tabuleiro={}, jogadas=jogadas)

    @property
    def inicial(self):
        '''Propriedade para estado inicial do jogo'''
        return self._inicial

    @property
    def dimensoes(self):
        '''Propriedade para as dimenões do tabuleiro'''
        return (self._largura, self._altura)

    @classmethod
    def acoes(cls, estado):
        """Retorna lista de ações possíveis"""
        return estado.jogadas

    def resultado(self, estado, jogada):
        """Retorna o resultacao da aplicação de uma jogada em um estado"""
        if jogada not in estado.jogadas:
            return estado  # Jogada inválida!
        tabuleiro = estado.tabuleiro.copy()
        tabuleiro[jogada] = estado.jogador
        jogadas = list(estado.jogadas)
        jogadas.remove(jogada)
        return Estado(jogador=estado.jogador, tabuleiro=tabuleiro, jogadas=jogadas)

    @classmethod
    def oponente(cls, jogador):
        '''Retorna o oponente do jogador'''
        if jogador == XIS:
            return BOL
        return XIS

    @classmethod
    def converte_tabuleiro(cls, lista_linhas):
        '''Converte lista de linhas para tabuleiro'''
        lista_jogadas = [(col, lin) for col in range(1, 3 + 1)
                         for lin in range(1, 3 + 1)]
        tabuleiro = {}
        for lin, linha in enumerate(lista_linhas):
            for col, valor in enumerate(linha):
                if valor == XIS or valor == BOL:
                    jogada = (col+1, lin+1)
                    lista_jogadas.remove(jogada)
                    tabuleiro[jogada] = valor
        return tabuleiro, lista_jogadas

    def eh_terminal(self, estado):
        """Retorna True se o estado for terminal"""
        if not self.acoes(estado):
            return True
        if self.eh_vencedor(estado, XIS) or self.eh_vencedor(estado, BOL):
            return True
        return False

    def eh_vencedor(self, estado, jogador):
        '''Returna verdadeiro se o jogador atual venceu'''
        for delta in [(0, 1), (1, 0), (1, 1), (1, -1)]:
            if self.busca_linha(estado.tabuleiro, jogador, delta):
                return True
        return False

    def busca_linha(self, tabuleiro, jogador, delta):
        '''Busca uma linha de um jogador em uma direção delta'''
        delta_col, delta_lin = delta
        for col in range(1, self._largura+1):
            for lin in range(1, self._altura+1):
                if tabuleiro.get((col, lin)) == jogador:
                    linha = True
                    j_col, j_lin = col, lin
                    for _ in range(self._sequencia-1):
                        j_col += delta_col
                        if j_col < 1 or j_col > self._largura:
                            linha = False
                            break
                        j_lin += delta_lin
                        if j_lin < 1 or j_lin > self._altura:
                            linha = False
                            break
                        if tabuleiro.get((j_col, j_lin)) != jogador:
                            linha = False
                            break
                    if linha:
                        return True
        return False

    @classmethod
    def jogador_atual(cls, estado):
        """Retorna o jogador a fazer a jogada"""
        return estado.jogador

    def mostra(self, estado):
        """Mostra o estado atual do jogo"""
        if self._display:
            tabuleiro = estado.tabuleiro
            numeros_col = [str(n) for n in range(1, self._largura + 1)]
            print('  ' + '|'.join(numeros_col))
            for lin in range(1, self._altura + 1):
                print('--' + '-'*(self._largura*2))
                print(str(lin) + '|', end='')
                for col in range(1, self._largura + 1):
                    print(tabuleiro.get((col, lin), '.'), '|', sep='', end='')
                print()
            print('--' + '-'*(self._largura*2))

    def jogada(self, jogador, estado):
        '''Faz uma jogada de um jogador'''
        if self._limite is None:
            jogada = jogador.faz_jogada(self, estado)
        else:
            jogada = self.jogada_timeout(jogador, estado)
        return jogada

    def jogar(self, jogador1, jogador2, passo=False):
        '''Executa um jogo'''
        vencedor = 0
        estado = self._inicial
        lista_jogadores = [jogador1, jogador2]
        while True:
            jogador = lista_jogadores.pop(0)
            self.mostra(estado)
            if self._display:
                print('\nPróximo jogador:', jogador.nome, '-', estado.jogador)
            jogada = self.jogada(jogador, estado)
            novo_estado = self.resultado(estado, jogada)
            if estado.tabuleiro != novo_estado.tabuleiro:
                estado = novo_estado
                if self.eh_vencedor(estado, estado.jogador):
                    self.mostra(estado)
                    print('\nVENCEDOR:', jogador.nome, '-', estado.jogador)
                    if jogador == jogador1:
                        vencedor = 1
                    else:
                        vencedor = -1
                    break
                if self.eh_terminal(estado):
                    self.mostra(estado)
                    print('\nEMPATE!')
                    vencedor = 0
                    break
                lista_jogadores.append(jogador)
                # Muda jogador
                oponente = self.oponente(estado.jogador)
                estado = Estado(jogador=oponente, tabuleiro=estado.tabuleiro,
                                jogadas=estado.jogadas)
            if passo:
                input()
        return vencedor

    def jogada_timeout(self, jogador, estado):
        '''Jogada thread with timeout'''
        result = Queue()
        jogada_proc = Process(target=faz_jogada,
                              args=(self, jogador, estado, result))
        jogada_proc.start()
        jogada_proc.join(self._limite)
        jogada_proc.kill()
        if not result.empty():
            return result.get()
        print('Timeout for', jogador.nome)
        jogador_aleatorio = JogadorAleatorio('', posicoes=jogador.posicoes)
        return jogador_aleatorio.faz_jogada(self, estado)


def faz_jogada(jogo, jogador, estado, result):
    '''Pega jogada de jogador'''
    jogada = jogador.faz_jogada(jogo, estado)
    result.put(jogada)

class JogoConecta4(JogoVelha):
    '''Jogo conecta 4'''

    def __init__(self, metricas=(8, 6, 4), display=True, limite=None):
        super().__init__(metricas, display, limite)
        jogadas = list(range(1, self._largura + 1))
        ini = self._inicial
        self._inicial = Estado(ini.jogador, ini.tabuleiro, jogadas)

    def resultado(self, estado, jogada):
        if jogada not in estado.jogadas:
            return estado  # Jogada inválida!
        tabuleiro = estado.tabuleiro.copy()
        linha = self._get_linha(jogada, tabuleiro)
        tabuleiro[(jogada, linha)] = estado.jogador
        jogadas = list(estado.jogadas)
        if linha == 1:
            jogadas.remove(jogada)
        return Estado(jogador=estado.jogador, tabuleiro=tabuleiro, jogadas=jogadas)

    def _get_linha(self, coluna, tabuleiro):
        '''Retorna menor linha para jogada em coluna'''
        jogadas = list(tabuleiro.keys())
        linhas = [lin for (col, lin) in jogadas
                  if col == coluna]
        if not linhas:
            return self._altura
        return min(linhas) - 1

class Jogador:
    '''Jogador de um jogo'''

    def __init__(self, nome, posicoes=1):
        self._nome = nome
        self._posicoes = posicoes

    @property
    def nome(self):
        '''Nome do jogador'''
        return self._nome

    @property
    def posicoes(self):
        '''Número de posições que o jogador deve ter na jogada'''
        return self._posicoes

    def faz_jogada(self, jogo, estado):
        '''Informa uma jogada para o tabuleiro'''
        raise NotImplementedError


class JogadorMiniMax(Jogador):
    '''Jogador com busca minimax'''

    def faz_jogada(self, jogo, estado):
        lista_jogadas = []
        for jogada in jogo.acoes(estado):
            novo_estado = jogo.resultado(estado, jogada)
            oponente = jogo.oponente(estado.jogador)
            novo_estado = Estado(
                oponente, novo_estado.tabuleiro, novo_estado.jogadas)
            valor = self._min(jogo, novo_estado, estado.jogador)
            lista_jogadas.append((valor, jogada))
        lista_jogadas.sort()
        melhor = lista_jogadas[-1]
        return melhor[1]

    def _max(self, jogo, estado, jogador_max):
        if jogo.eh_terminal(estado):
            return self.utilidade(jogo, estado, jogador_max)
        valor = float('-inf')
        for jogada in jogo.acoes(estado):
            novo_estado = jogo.resultado(estado, jogada)
            oponente = jogo.oponente(estado.jogador)
            novo_estado = Estado(
                oponente, novo_estado.tabuleiro, novo_estado.jogadas)
            valor = max(valor, self._min(jogo, novo_estado, jogador_max))
        return valor

    def _min(self, jogo, estado, jogador_max):
        if jogo.eh_terminal(estado):
            return self.utilidade(jogo, estado, jogador_max)
        valor = float('inf')
        for jogada in jogo.acoes(estado):
            novo_estado = jogo.resultado(estado, jogada)
            oponente = jogo.oponente(estado.jogador)
            novo_estado = Estado(
                oponente, novo_estado.tabuleiro, novo_estado.jogadas)
            valor = min(valor, self._max(jogo, novo_estado, jogador_max))
        return valor

    @classmethod
    def utilidade(cls, jogo, estado, jogador_max):
        '''Rertorna a utilidade do estado'''
        oponente = jogo.oponente(jogador_max)
        if jogo.eh_vencedor(estado, jogador_max):
            return 1
        if jogo.eh_vencedor(estado, oponente):
            return -1
        return 0


class JogadorAlphaBeta(Jogador):
    '''Jogador com busca minimax'''

    def faz_jogada(self, jogo, estado):
        alpha = float('-inf')
        beta = float('inf')
        lista_jogadas = []
        for jogada in jogo.acoes(estado):
            novo_estado = jogo.resultado(estado, jogada)
            oponente = jogo.oponente(estado.jogador)
            novo_estado = Estado(
                oponente, novo_estado.tabuleiro, novo_estado.jogadas)
            valor = self._min(jogo, novo_estado, estado.jogador, alpha, beta)
            lista_jogadas.append((valor, jogada))
        lista_jogadas.sort()
        melhor = lista_jogadas[-1]
        return melhor[1]

    def _max(self, jogo, estado, jogador_max, alpha, beta):
        if jogo.eh_terminal(estado):
            return self.utilidade(jogo, estado, jogador_max)
        valor = float('-inf')
        for jogada in jogo.acoes(estado):
            novo_estado = jogo.resultado(estado, jogada)
            oponente = jogo.oponente(estado.jogador)
            novo_estado = Estado(
                oponente, novo_estado.tabuleiro, novo_estado.jogadas)
            valor = max(valor, self._min(
                jogo, novo_estado, jogador_max, alpha, beta))
            if valor >= beta:
                return valor
            alpha = max(alpha, valor)
        return valor

    def _min(self, jogo, estado, jogador_max, alpha, beta):
        if jogo.eh_terminal(estado):
            return self.utilidade(jogo, estado, jogador_max)
        valor = float('inf')
        for jogada in jogo.acoes(estado):
            novo_estado = jogo.resultado(estado, jogada)
            oponente = jogo.oponente(estado.jogador)
            novo_estado = Estado(
                oponente, novo_estado.tabuleiro, novo_estado.jogadas)
            valor = min(valor, self._max(
                jogo, novo_estado, jogador_max, alpha, beta))
            if valor <= alpha:
                return valor
            beta = max(beta, valor)
        return valor

    @classmethod
    def utilidade(cls, jogo, estado, jogador_max):
        '''Rertorna a utilidade do estado'''
        oponente = jogo.oponente(jogador_max)
        if jogo.eh_vencedor(estado, jogador_max):
            return 1
        if jogo.eh_vencedor(estado, oponente):
            return -1
        return 0

class JogadorHumano(Jogador):
    '''Jogador de velha humano'''

    def faz_jogada(self, jogo, estado):
        while True:
            try:
                jogada = input('\nInforme a jogada para ' + self._nome + ': ')
                if self._posicoes == 1:
                    return int(jogada)
                return tuple([int(n) for n in jogada.split()])
            except:  # pylint: disable=bare-except
                print('Posição inválida no jogo! Informe novamente.')
                input()


class JogadorAleatorio(Jogador):
    '''Jogador de velha que faz jogadas aleatórias'''

    def faz_jogada(self, jogo, estado):
        tabuleiro = estado.tabuleiro
        if self._posicoes == 1:
            jogadas = estado.jogadas[:]
            shuffle(jogadas)
            return jogadas[0]
        largura, altura = jogo.dimensoes
        jogadas = [(x, y) for x in range(1, largura + 1)
                   for y in range(1, altura + 1)]
        jogadas_realizadas = set(tabuleiro.keys())
        jogadas = list(set(jogadas) - jogadas_realizadas)
        shuffle(jogadas)
        return jogadas[0]

