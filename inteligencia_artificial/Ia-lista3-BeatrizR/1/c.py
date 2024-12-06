class Nodo:
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
        return self.custo < nodo.custo

    def __eq__(self, outro):
        return isinstance(outro, Nodo) and self.estado == outro.estado

    @property
    def estado(self):
        return self._estado

    @property
    def custo(self):
        return self._custo

    @property
    def profundidade(self):
        '''Profundidade do nó'''
        return self._profundidade

    @property
    def pai(self):
        '''Pai do nó'''
        return self._pai

    @property
    def acao(self):
        '''Acao do nó'''
        return self._acao

    def cria_no_filho(self, problema, acao):
        '''Cria nó filho'''
        proximo_estado = problema.resultado(self._estado, acao)
        custo_filho = problema.custo(self._custo, self._estado, acao,
                                     proximo_estado)
        no_filho = Nodo(proximo_estado, self, acao, custo_filho)
        return no_filho

    def expande(self, problema):
        '''Expande o nó, retornando a lista de filhos'''
        return [self.cria_no_filho(problema, acao)
                for acao in problema.acoes(self._estado)]

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
