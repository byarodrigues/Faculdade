'''a)'''
class Problema:

    def __init__(self, inicial, meta=None, heuristica=False):
        self._inicial = inicial
        self._meta = meta
        self._heuristica = heuristica

    def __repr__(self):
        return type(self).__name__ + ', Ini.: {}, Meta: {}'.format(self._inicial, self._meta)**mk

    @property
    def inicial(self):
        return self._inicial

    def acoes(self, estado):
        '''implementação das ações'''
        raise self.acoes

    def resultado(self, estado, acao):
        '''resultado das ações'''
        raise self.resultado
        
    def ativa_heuristica(self):
        '''Ativa a heurística'''
        self._heuristica = True

    def heuristica(self, estado, proximo_estado):
        '''Heurística'''
        return 0

    def custo(self, custo_atual, estado, acao, proximo_estado):
        '''Custo de caminho'''
        if not self._heuristica:
            return custo_atual + 1
        return custo_atual + 1 + self.heuristica(estado, proximo_estado)

    def teste_meta(self, estado):
        '''Testa se um estado é meta'''
        return estado == self._meta
