from a import Problema
'''
Represente o problema do aspirador de pó através de uma
classe herdando da classe Problema. Considere os 
seguintes pontos:

• Existe mais de um estado meta? Como tratar essa 
questão?
• Implemente uma heurística para usar com o algoritmo 
A*. Seria correto deixar o cômodo atual
sujo e ir para outro cômodo?
• Execute os algoritmos de buscas desenvolvidos 
partindo de um estado em que ambos cômodos
estejam sujos.
'''
import logging
import sys
import logging
from collections import deque
from queue import PriorityQueue

LOG = logging.getLogger(__name__)

def config_log(debugging):
    '''Configura o log'''
    formato = logging.Formatter('')
    arquivo = logging.FileHandler('/tmp/busca.log')
    arquivo.setFormatter(formato)
    console = logging.StreamHandler()
    console.setFormatter(formato)
    LOG.handlers.clear()
    LOG.addHandler(arquivo)
    LOG.addHandler(console)
    if debugging:
        LOG.setLevel(logging.DEBUG)
    else:
        LOG.setLevel(logging.INFO)

ACOES = ['L','E','D']
METAS = [('A','0','0'),('B','0','0'),('C','0','0')]
class aspirador(Problema):
    def __init__(self, inicial):
        super().__init__(inicial)
        self._meta = [('A', 0, 0), ('B', 0, 0)]

    def acoes(self, estado):
        return ['L', 'E', 'D']

    def resultado(self, estado, acao):
        novo_estado = list(estado)
        if acao == 'L':
            if novo_estado[0] == 'A':
                novo_estado[1] = 0
            else:
                novo_estado[2] = 0
        elif acao == 'E' and novo_estado[0] == 'B':
            novo_estado[0] = 'A'
        elif acao == 'E' and novo_estado[0] == 'C':
            novo_estado[0] = 'B'
        elif acao == 'D' and novo_estado[0] == 'A':
            novo_estado[0] = 'B'
        elif acao == 'D' and novo_estado[0] == 'B':
            novo_estado[0] = 'C'
        return tuple(novo_estado)
        
    def teste_meta(self,estado):
        if estado in self._meta:
            return True
        return False

    def heuristica(self, estados, proximo_estado):
        if estados[0] == 'A' and estados[1] == proximo_estado[1] == 1:
            return 3
        if estados[0] == 'B' and estados[2] == proximo_estado[2] == 1:
            return 3
        return 0

def main():
    config_log(True)
    estado = ('A', 1, 1)
    problema_aspirador = aspirador(estado)

if __name__ == '__main__':
    main()