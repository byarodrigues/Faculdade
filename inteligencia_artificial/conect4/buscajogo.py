#!/usr/bin/python3
# -*- coding: utf-8 -*-

'''
Algoritmos de busca
'''

import logging
import sys
from collections import deque
from queue import PriorityQueue

# Log global
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


class Problema:
    '''Classe abstrata para representação de problemas de busca'''

    def __init__(self, inicial, meta=None, heuristica=False):
        '''Construtor'''
        self._inicial = inicial
        self._meta = meta
        self._heuristica = heuristica

    def __repr__(self):
        return type(self).__name__ + ', Ini.: {}, Meta: {}'.format(self._inicial, self._meta)**mk

    @property
    def inicial(self):
        '''Propriedade para estado do nó'''
        return self._inicial

    def acoes(self, estado):
        '''Retorna as ações que podem ser aplicada a um estado'''
        raise NotImplementedError

    def custo(self, custo_atual, estado, acao, proximo_estado):
        '''Custo de caminho'''
        if not self._heuristica:
            return custo_atual + 1
        return custo_atual + 1 + self.heuristica(estado, proximo_estado)

    def ativa_heuristica(self):
        '''Ativa a heurística'''
        self._heuristica = True

    def heuristica(self, estado, proximo_estado):
        '''Heurística'''
        return 0

    def resultado(self, estado, acao):
        '''Retorna o resultado da aplicação de ação em estado'''
        raise NotImplementedError

    def teste_meta(self, estado):
        '''Testa se um estado é meta'''
        return estado == self._meta


class ProblemaTeste(Problema):
    '''Representação de problemas para teste com estatísticas'''
    def __init__(self, problema):
        self._problema = problema
        self._visitados = self._gerados = 0
        self._solucao = None

    def acoes(self, estado):
        return self._problema.acoes(estado)

    def resultado(self, estado, acao):
        self._gerados += 1
        return self._problema.resultado(estado, acao)

    def ativa_heuristica(self):
        return self._problema.ativa_heuristica()

    def teste_meta(self, estado):
        self._visitados += 1
        result = self._problema.teste_meta(estado)
        if result:
            self._solucao = estado
        return result

    def custo(self, custo_atual, estado, acao, proximo_estado):
        '''Custo de caminho'''
        # return custo_atual + self._problema.custo(custo_atual, estado, acao,
                                                #   proximo_estado)
        return self._problema.custo(custo_atual, estado, acao, proximo_estado)

    def __getattr__(self, attr):
        return getattr(self._problema, attr)

    def __repr__(self):
        return 'Ger.: {:d}, Vis.: {:d}, Sol.: {}>'.format(self._gerados,
                                                          self._visitados,
                                                          str(self._solucao))


class Nodo:
    '''Nodo da árvore de busca'''

    def __init__(self, estado, pai=None, acao=None, custo=0):
        '''Cria o nó'''
        self._estado = estado
        self._pai = pai
        self._acao = acao
        self._custo = custo
        self._profundidade = 0
        if pai:
            self._profundidade = pai.profundidade + 1

    def __repr__(self):
        return '<{}>'.format(self._estado)

    def __lt__(self, nodo):
        # Compara nós pelo custo (usado em fila de prioridade)
        return self.custo < nodo.custo

    @property
    def estado(self):
        '''Propriedade para estado do nó'''
        return self._estado

    @property
    def custo(self):
        '''Propriedade para custo do nó'''
        return self._custo

    @property
    def profundidade(self):
        '''Propriedade para profundidade do nó'''
        return self._profundidade

    @property
    def pai(self):
        '''Propriedade para pai do nó'''
        return self._pai

    @property
    def acao(self):
        '''Propriedade para acao do nó'''
        return self._acao

    def expande(self, problema):
        '''Expande o nó, retornando a lista de filhos'''
        return [self.cria_no_filho(problema, acao)
                for acao in problema.acoes(self._estado)]

    def cria_no_filho(self, problema, acao):
        '''Cria nó filho'''
        proximo_estado = problema.resultado(self._estado, acao)
        custo_filho = problema.custo(self._custo, self._estado, acao,
                                     proximo_estado)
        no_filho = Nodo(proximo_estado, self, acao, custo_filho)
        return no_filho

    def caminho(self):
        '''Caminho da raiz até o nó'''
        atual, passos = self, []
        while atual:
            passos.append(atual)
            atual = atual.pai
        passos.reverse()
        return passos

    def solucao(self):
        '''Sequência de ações para chegar ao nó'''
        return [nodo.acao for nodo in self.caminho()[1:]]

    def __eq__(self, outro):
        return isinstance(outro, Nodo) and self.estado == outro.estado


def busca_profundidade(problema):
    '''
    Busca em profundidade em grafos (não repete estados)
    '''
    LOG.debug('Busca em profundidade:')
    inicio = Nodo(problema.inicial)
    borda = [inicio]  # Pilha
    explorados = set()
    while borda:
        nodo = borda.pop()
        LOG.debug('%s%s [%s]', '  '*nodo.profundidade, nodo, nodo.acao)
        if problema.teste_meta(nodo.estado):
            return nodo
        explorados.add(nodo.estado)
        for filho in nodo.expande(problema):
            if filho.estado not in explorados and filho not in borda:
                borda.append(filho)
    return None


def busca_largura(problema):
    '''Busca em largura em grafos (não repete estados)'''
    LOG.debug('Busca em largura:')
    nodo = Nodo(problema.inicial)
    if problema.teste_meta(nodo.estado):
        return nodo
    borda = deque([nodo])
    explorados = set()
    while borda:
        nodo = borda.popleft()
        LOG.debug('%s%s [%s]', '  '*nodo.profundidade, nodo, nodo.acao)
        explorados.add(nodo.estado)
        for filho in nodo.expande(problema):
            if filho.estado not in explorados and filho not in borda:
                if problema.teste_meta(filho.estado):
                    LOG.debug('%s [%s]', filho, filho.acao)
                    return filho
                borda.append(filho)
    return None


def busca_custo_uniforme(problema, nome='Busca de custo uniforme:'):
    '''Busca de custo uniforme'''
    LOG.debug(nome)
    nodo = Nodo(problema.inicial)
    borda = PriorityQueue()
    borda.put(nodo)
    explorados = set()
    while borda:
        nodo = borda.get()
        LOG.debug('%s%s [%s] (%s)    PAI = %s', '  '*nodo.profundidade, nodo, nodo.acao,
                  nodo.custo, nodo.pai)
        if problema.teste_meta(nodo.estado):
            return nodo
        explorados.add(nodo.estado)
        for filho in nodo.expande(problema):
            if filho.estado not in explorados and filho not in borda.queue:
                borda.put(filho)
            elif filho in borda.queue:
                pos_filho = borda.queue.index(filho)
                filho_antigo = borda.queue[pos_filho]
                if filho.custo < filho_antigo.custo:
                    del borda.queue[pos_filho]
                    borda.put(filho)
    return None


def busca_aestrela(problema):
    '''Busca A*'''
    problema.ativa_heuristica()
    return busca_custo_uniforme(problema, 'Busca A*:')


def _bplr(nodo, problema, limite):
    LOG.debug('%s%s [%s]', '  '*nodo.profundidade, nodo, nodo.acao)
    if problema.teste_meta(nodo.estado):
        return nodo
    if limite == 0:
        LOG.debug('CORTE')
        return 'CORTE'
    corte = False
    for filho in nodo.expande(problema):
        result = _bplr(filho, problema, limite - 1)
        if result == 'CORTE':
            corte = True
        elif result is not None:
            return result
    if corte:
        return 'CORTE'
    return None


def busca_profundidade_limitada(problema, limite=5,
                                nome='Busca em profundidade limitada'):
    '''Busca em profundidade limitada'''
    LOG.debug('%s (%s):', nome, limite)
    return _bplr(Nodo(problema.inicial), problema, limite)


def busca_aprofundamento_iterativo(problema, maximo=sys.maxsize):
    '''Busca de aprofundamento iterativo'''
    LOG.debug('Busca de aprofundamento iterativo:')
    for profundidade in range(maximo):
        result = busca_profundidade_limitada(problema, profundidade,
                                             'Profundidade:')
        if result != 'CORTE':
            return result
    return None


def compara_buscas(lista_problemas, lista_algoritmos=None):
    '''Compara algoritmos de busca para uma lista de problemas'''
    if lista_algoritmos is None:
        lista_algoritmos = [busca_largura,
                            busca_profundidade,
                            busca_aprofundamento_iterativo,
                            busca_custo_uniforme,
                            busca_aestrela]
    for problema in lista_problemas:
        print('='*100)
        print(problema)
        print('='*100)
        for algoritmo in lista_algoritmos:
            prob = ProblemaTeste(problema)
            resposta = algoritmo(prob)
            LOG.debug('-'*50)
            print(type(problema).__name__, ',', algoritmo.__name__, ',', prob)
            if resposta is not None:
                print('Solução:', resposta.solucao())
