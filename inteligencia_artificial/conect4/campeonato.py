#!/usr/bin/python3 -u
# -*- coding: utf-8 -*-

from jogos import JogadorAleatorio, JogadorMiniMax, JogadorAlphaBeta, JogoConecta4


LISTA_JOGADORES = [
    (JogadorAleatorio, 'Aleatório'),
    (JogadorMiniMax, 'Minimax'),
    (JogadorAlphaBeta, 'AlphaBeta'),
]

LIMITE_TEMPO = 5

class Campeonato:
    '''Classe para controlar o campeonato'''
    def __init__(self, jogo, jogadores, limite, posicoes=1):
        self._jogo = jogo
        self._jogadores = jogadores
        self._limite = limite
        self._posicoes = posicoes
        self._pontos = {jogador:0 for jogador in range(len(jogadores))}

    def faz_jogo(self, num_jogo, num_jogador1, num_jogador2):
        '''Jogo entre dois jogadores'''
        jogo = self._jogo
        jogo = jogo(limite=self._limite, display=True)
        jogador, nome1 = self._jogadores[num_jogador1]
        jogador1 = jogador(nome1, self._posicoes)
        jogador, nome2 = self._jogadores[num_jogador2]
        jogador2 = jogador(nome2, self._posicoes)
        print('Jogo ', num_jogo, ': ', nome1, ' x ', nome2, sep='')
        vencedor = jogo.jogar(jogador1, jogador2)
        if vencedor == 1:
            self._pontos[num_jogador1] += 3
        elif vencedor == -1:
            self._pontos[num_jogador2] += 3
        else:
            self._pontos[num_jogador1] += 1
            self._pontos[num_jogador2] += 1
        # print('Resultado: ', resultado)
        print('\n\n' + '='*50)
        input()

    def faz_campeonato(self):
        '''Campeonato entre todos os jogadores'''
        num_jogo = 1
        for num_jogador1 in range(len(self._jogadores)):
            for num_jogador2 in range(num_jogador1+1, len(self._jogadores)):
                self.faz_jogo(num_jogo, num_jogador1, num_jogador2)
                num_jogo += 1
        for num_jogador1 in range(len(self._jogadores)):
            for num_jogador2 in range(num_jogador1+1, len(self._jogadores)):
                self.faz_jogo(num_jogo, num_jogador2, num_jogador1)
                num_jogo += 1
        lista_classificacao = []
        for posicao, jogador in enumerate(self._jogadores):
            _, nome = jogador
            pontos = self._pontos[posicao]
            lista_classificacao.append((pontos, nome))
        lista_classificacao.sort()
        lista_classificacao.reverse()
        print('Classificação:')
        for pontos, nome in lista_classificacao:
            print(nome, ':', pontos)


if __name__ == '__main__':
    CAMPEONATO = Campeonato(JogoConecta4, LISTA_JOGADORES, LIMITE_TEMPO)
    CAMPEONATO.faz_campeonato()
