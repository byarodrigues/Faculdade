'''
Conect4-I.A.-BeatrizRodrigues
'''

import logging
from collections import namedtuple
from multiprocessing import Process, Queue
from random import shuffle

XIS = 'X'
BOL = 'O'

Estado = namedtuple('Estado', 'jogador, tabuleiro, jogadas')

class JogoConecta4:
    '''Jogo conecta 4'''

    def __init__(self, metricas=(8, 6, 4), display=True, limite=None):
        largura, altura, sequencia = metricas
        self._largura = largura
        self._altura = altura
        self._sequencia = sequencia
        self._display = display
        self._limite = limite
        super().__init__(metricas, display, limite)
        jogadas = list(range(1, self._largura + 1))
        ini = self._inicial
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
        if jogada not in estado.jogadas:
            return estado  # Jogada inválida!
        tabuleiro = estado.tabuleiro.copy()
        linha = self._get_linha(jogada, tabuleiro)
        tabuleiro[(jogada, linha)] = estado.jogador
        jogadas = list(estado.jogadas)
        if linha == 1:
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
    
    def _get_linha(self, coluna, tabuleiro):
        '''Retorna menor linha para jogada em coluna'''
        jogadas = list(tabuleiro.keys())
        linhas = [lin for (col, lin) in jogadas
                  if col == coluna]
        if not linhas:
            return self._altura
        return min(linhas) - 1
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


    def heuristica(board):
    # check for wins in rows
        for i in range(len(board)):
            for j in range(len(board[0])-3):
                if board[i][j] == board[i][j+1] == board[i][j+2] == board[i][j+3]:
                    return True
    # check for wins in columns
        for i in range(len(board)-3):
            for j in range(len(board[0])):
                if board[i][j] == board[i+1][j] == board[i+2][j] == board[i+3][j]:
                    return True
    # check for wins in diagonal top left to bottom right
        for i in range(len(board)-3):
            for j in range(len(board[0])-3):
                if board[i][j] == board[i+1][j+1] == board[i+2][j+2] == board[i+3][j+3]:
                    return True
    # check for wins in diagonal top right to bottom left
        for i in range(len(board)-3):
            for j in range(3, len(board[0])):
                if board[i][j] == board[i+1][j-1] == board[i+2][j-2] == board[i+3][j-3]:
                    return True
                return False

        board = [[0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0]]
        print(connectfour(board)) # should return False

        board = [[1,1,1,1,0,0,0],
                [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0]]
        print(connectfour(board)) # should return True

def main():
    '''Main'''
    
    parser = argparse.ArgumentParser('Formula')
    parser.add_argument('-f', '--file', help='Input file')
    parser.add_argument('-t', '--text', help='Input file')
    parser.add_argument('-D', '--debug', action="store_true",
                        default=False, help='Debug execution')
    args = parser.parse_args()
    if args.text:
        process_formula(args.text)
    if args.file:
        file = open(args.file)
        for line in file:
            process_formula(line)
        file.close()


if __name__ == '__main__':
    main()
