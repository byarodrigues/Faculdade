from pagina import Pagina, Folha

'''
Classe que envolve todo a abstração da arvore B+
'''
class Arvore(object):
    
    '''
    Funcão que inicia a estrutura de arvore
    '''
    def __init__(self, grau):
        self.grau = grau
        self.raiz = Folha(None, None, None, self.grau)
    
    '''
    Função que insere o valor na arvore, mas busca se ele já esta presente
    '''
    def inserir(self, valor):
        d, folha, flag = self.buscar(valor, self.raiz)
        if flag:
            print('O valor {} já está presente na árvore'.format(valor))
        else:
            l = folha.inserir(valor)
            print("O valor {} foi inserido com sucesso na árvore".format(valor))
            if l != 0:
                self.raiz = l
    '''
    Função que busca um valor e se ele estiver presente, faz sua deleção
    '''
    def deletar(self, valor):
        d, folha, flag = self.buscar(valor, self.raiz)
        if flag:
            l = folha.remover(valor)
            print("O valor {} foi deletado com sucesso da árvore".format(valor))
            if l != 0:
                self.raiz = l
        else:
            print('O valor {} não está presente na árvore'.format(valor))
    
    '''
    Função que varre toda a lista de páginas e verifica se um valor esta ou não presente
    '''
    def buscar(self, valor, pagina):
        while pagina.folha != True:
            flag = 0
            for i in range(len(pagina.chaves)):
                if pagina.chaves[i] >= valor:
                    pagina = pagina.filhos[i]
                    flag = 1
                    break
            if flag == 0 and len(pagina.filhos ) > len(pagina.chaves):
                pagina = pagina.filhos[len(pagina.chaves)]
        print("Buscando pela chave {}".format(valor), pagina.chaves)
        try:
            index = pagina.chaves.index(valor)
            return index, pagina, 1
        except:
            return 0, pagina, 0          