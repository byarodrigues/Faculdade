'''
Implemente a classe QuebraCabeca herdando da classe Problema para implementar o problema do
quebra cabeça deslizante de 8 peças. Considere os seguintes pontos:
• Implemente uma heurística para usar com o algoritmo A*;
• Execute os algoritmos de buscas desenvolvidos partindo de um estado aleatório.
'''
import logging
import sys
import logging
from collections import deque
from queue import PriorityQueue
from a import Problema
from d import busca_largura, busca_aestrela, busca_aprofundamento_iterativo, busca_custo_uniforme

LOG = logging.getLogger(__name__)

ACOES = ['C', 'B', 'E', 'D']
META = (1, 2, 3, 4, 5, 6, 7, 8, 9)

class quabracabeca(Problema):

    def __init__(self, inicial, meta=META):
        super().__init__(inicial, meta)

    def acoes(self, estado):
        acoes = ACOES[:]
        pos_vazia = estado.index(0)
        if pos_vazia % 3 == 0:
            acoes.remove('E')
        if pos_vazia < 3:
            acoes.remove('C')
        if pos_vazia % 3 == 2:
            acoes.remove('D')
        if pos_vazia > 5:
            acoes.remove('B')
        return acoes
    
    def resultado(self, estado, acao):
        pos_vazia = estado.index(0)
        novo_estado = list(estado)
        delta = {'C': -3, 'B': 3, 'E': -1, 'D': 1}
        vizinho = pos_vazia + delta[acao]
        novo_estado[pos_vazia], novo_estado[vizinho] = novo_estado[vizinho], novo_estado[pos_vazia]
        return tuple(novo_estado)

    def heuristica(self, estado, proximo_estado):
        erradas = 0
        for posicao, valor in enumerate(proximo_estado):
            if valor != self._meta[posicao]:
                erradas += 1
        return erradas
    
def main():
    lista_jogos = []
    estado = ('A', 'B', 'C', 'D')
    for _ in range(1):
        jogo = quabracabeca(estado)
        lista_jogos.append(jogo)

if __name__ == '__main__':
    main()