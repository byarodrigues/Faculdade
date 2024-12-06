from a import Problema

class ProblemaTeste(Problema):
    def __init__(self, problema):
        self._problema = problema
        self._visitados = self._gerados = 0
        self._solucao = None

    def acoes(self, estado):
        return self._problema.acoes(estado)

    def custo(self, custo_atual, estado, acao, proximo_estado):
        return self._problema.custo(custo_atual, estado, acao, proximo_estado)

    def ativa_heuristica(self):
        return self._problema.ativa_heuristica()

    def resultado(self, estado, acao):
        self._gerados += 1
        return self._problema.resultado(estado, acao)

    def teste_meta(self, estado):
        self._visitados += 1
        result = self._problema.teste_meta(estado)
        if result:
            self._solucao = estado
        return result

    def __getattr__(self, attr):
        return getattr(self._problema, attr)

    def __repr__(self):
        return 'Ger.: {:d}, Vis.: {:d}, Sol.: {}>'.format(self._gerados,
                                                          self._visitados,
                                                          str(self._solucao))
