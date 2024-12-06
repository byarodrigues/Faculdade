import logging
LOG = logging.getLogger(__name__)
import sys
from collections import deque
from queue import PriorityQueue

from c import Nodo
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
    problema.ativa_heuristica()
    return busca_custo_uniforme(problema, 'Busca A*:')


