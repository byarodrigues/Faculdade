from pagina import Pagina, Folha


class Arvore(object):
    
    def __init__(self, grau):
        self.grau = grau
        self.raiz = Folha(None, None, None, self.grau)
    
    '''
    Insere o valor na arvore
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
    Busca um valor e se ele estiver presente deleta
    '''
    def remove(self, valor):
        d, folha, flag = self.buscar(valor, self.raiz)
        if flag:
            l = folha.remover(valor)
            print("O valor {} foi deletado com sucesso da árvore".format(valor))
            if l != 0:
                self.raiz = l
        else:
            print('O valor {} não está presente na árvore'.format(valor))
    
    '''
    Verifica se um valor esta ou não presente
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

    '''
    Busca por uma chave utiluizando o método de busca por igualdade
    '''       
    def buscar_por_igualdade(self, valor, pagina):
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
        if valor in pagina.chaves:
            index = pagina.chaves.index(valor)
            return index, pagina, 1
        else:
            return None, None, 0
    '''
    Busca por uma chave utiluizando o método de busca por intervalo
    '''       
    def buscar_intervalo(self, inicio, fim, pagina):
        while pagina.folha != True:
            flag = 0
            for i in range(len(pagina.chaves)):
                if pagina.chaves[i] >= inicio:
                    pagina = pagina.filhos[i]
                    flag = 1
                    break
            if flag == 0 and len(pagina.filhos ) > len(pagina.chaves):
                pagina = pagina.filhos[len(pagina.chaves)]
        
        result = []
        for valor in pagina.chaves:
            if inicio <= valor <= fim:
                result.append(valor)
        
        return result
