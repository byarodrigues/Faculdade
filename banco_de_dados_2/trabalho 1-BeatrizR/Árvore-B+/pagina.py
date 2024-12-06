import math


class Pagina(object):

    def __init__(self, pai, grau):
        self.pai = pai
        self.grau = grau
        self.anterior = None
        self.proximo = None
        self.chaves = list()
        self.filhos = list()
        self.folha = False
    
    def chaves(self):
        return self.chaves

    '''
    Insere no lugar exato e vê ainda se já está ou não nas paginas folha
    '''
    def inserir(self, chave, filho):
        flag = 0
        for i in range(len(self.chaves)):
            if self.chaves[i] > chave:
                self.chaves = self.chaves[:i] + [chave] + self.chaves[i:]
                if self.filhos[i].chaves[-1] > filho.chaves[0]:
                    self.filhos = self.filhos[:i] + [filho] + self.filhos[i:]
                else:
                    self.filhos = self.filhos[:i+1] + [filho] + self.filhos[i+1:]
                flag = 1
                break
        if not flag:
            self.chaves.append(chave)
            self.filhos.append(filho)
        root = self.fazer_balanceamento() if len(self.chaves) >= self.grau else 0
        if filho.folha:
            self.atualizar_chaves()
        return root
    
    '''
    Atualiza as chaves no nivel folha
    '''    
    def atualizar_chaves(self):
        if self.filhos[0].folha:
            if len(self.filhos) >= int(math.ceil(self.grau/2)):
                l = list()
                for filho in self.filhos:
                    try:
                        l.append(filho.chaves[-1])
                    except IndexError: pass
                self.chaves = l[: len(self.filhos)-1]
            else:
                self.ajuste_irmao()
    
    def fazer_balanceamento(self):
        index = (self.grau+1)//2
        r = self.chaves[index-1]
        novo_no = Pagina(self.pai, self.grau)
        novo_no.chaves = self.chaves[index:]
        self.chaves = self.chaves[:index-1]
        novo_no.filhos = self.filhos[index: ]
        for filho in novo_no.filhos:
            filho.pai = novo_no
        self.filhos = self.filhos[:index]
        if self.pai == None:
            aux_no = Pagina(None, self.grau)
            aux_no.chaves.append(r)
            aux_no.filhos.append(self)
            aux_no.filhos.append(novo_no)
            self.pai = aux_no
            novo_no.pai = aux_no
            return aux_no
        else:
            root = self.pai.inserir(r, novo_no)
            return root
      
    def remover_ajuste(self):
        if self.filhos[0].folha == True:
            self.atualizar_chaves()
            if not self.pai:
                return self.filhos[0].pai
        return self.pai if not self.pai.pai else self.pai.remover_ajuste()
    
    '''
    Auxilia para ajustar os ponteiros de paginas irmãs ao atualizar suas chaves
    '''
    def ajuste_irmao(self):
        flag = 0
        if not self.pai:
            self.chaves = self.filhos[0].chaves
            self.filhos = []
        elif len(self.pai.chaves) == 1:
            if self.pai.filhos.index(self) == 0:
                no_esquerdo = self.pai.filhos[1]
                self.mesclar(no_esquerdo, 1)
            else:
                no_esquerdo = self.pai.filhos[0]
                self.mesclar(no_esquerdo, -1)
            for filho in self.filhos:
                filho.pai = self
            self.atualizar_chaves()
            self.pai = None
        else:
            i = self.pai.filhos.index(self) 
            if i < len(self.pai.filhos) - 1:
                no_direito = self.pai.filhos[i+1]
                self.mesclar(no_direito, 1)
            else:
                no_esquerdo = self.pai.filhos[i-1]
                self.mesclar(no_esquerdo, -1)
            for filho in self.filhos:
                filho.pai = self
            self.pai.ajuste_irmao()
    '''
    Faz a mescla das paginas na hora de atualizar 
    '''
    def mesclar(self, pagina, ord):
        if ord == 1:
            self.chaves = self.chaves + pagina.chaves
            self.filhos[0].folha_proximo = pagina.filhos[0]
            pagina.filhos[0].folha_anterior = self.filhos[0]
            self.filhos = self.filhos + pagina.filhos
        else:
            self.chaves =  pagina.chaves + self.chaves 
            pagina.filhos[0].folha_proximo = self.filhos[0]
            self.filhos[0].folha_anterior = pagina.filhos[0]
            self.filhos =  pagina.filhos + self.filhos
    
'''
Classe dedicada para paginas do tipo folha
'''
class Folha(Pagina):
   
    def __init__(self, folha_anterior, folha_proximo, pai, grau):
        self.pai = pai
        self.grau = grau
        self.folha_anterior = folha_anterior
        self.folha_proximo = folha_proximo
        self.chaves = list()
        self.folha = True
    '''
    Insere na lista de paginas folha
    '''
    def inserir(self, chave):
        flag = 0
        for i in range(len(self.chaves)):
            if self.chaves[i] > chave:
                self.chaves = self.chaves[:i] + [chave] + self.chaves[i:]
                flag = 1
                break
        if flag == 0:
            self.chaves.append(chave)
        if len(self.chaves) >= self.grau:
            root = self.fazer_balanceamento()
            return root 
        else:
            return 0
    
    '''
    Remove um valor da lista de paginas 
    '''
    def remover(self, value):
        self.chaves.remove(value)
        p = self.pai
        if not(len(self.chaves) >= self.grau//2):
            if self.folha_proximo != None:
                if self.folha_proximo.pai == p:
                    if len(self.chaves) + len(self.folha_proximo.chaves) <= self.grau-1:
                        self.mesclar(self.folha_proximo, 1)
                        p.filhos.remove(self.folha_proximo)
                        self.folha_proximo = self.folha_proximo.folha_proximo
                    elif (len(self.chaves) + len(self.folha_proximo.chaves))//2 >= self.grau//2:
                        count = 0
                        while len(self.chaves) < self.grau//2:
                            self.chaves.append(self.folha_proximo.chaves[count])
                            count += 1
                        self.folha_proximo.chaves = self.folha_proximo.chaves[count:]
            elif self.folha_anterior != None:
                if self.folha_anterior.pai == p:
                    if len(self.chaves) + len(self.folha_anterior.chaves) <= self.grau-1:
                        self.mesclar(self.folha_anterior, -1)
                        p.filhos.remover(self.folha_anterior)
                        self.folha_anterior = self.folha_anterior.folha_anterior
                        self.folha_anterior.folha_proximo = self
                    elif (len(self.chaves) + len(self.folha_anterior.chaves))//2 >= self.grau//2:
                        count = -1
                        while len(self.chaves) < self.grau//2:
                            self.chaves = [self.folha_anterior.chaves[count]] + self.chaves
                            count -= 1
                        self.folha_anterior.chaves = self.folha_anterior.chaves[:count+1]

    def fazer_balanceamento(self):
        index = (self.grau+1)//2
        r = self.chaves[index-1]
        flag = 0
        if self.folha_proximo == None or ((len(self.folha_proximo.chaves) + len(self.chaves)-index) > self.grau-1):
            nova_folha = Folha(self, None, self.pai, self.grau)
            try:
                self.folha_proximo.folha_anterior = nova_folha
            except: None
            nova_folha.folha_proximo = self.folha_proximo
            self.folha_proximo = nova_folha
            nova_folha.chaves = self.chaves[index:]
            self.chaves = self.chaves[:index]
            if not self.pai:
                aux_no = Pagina(None, self.grau)
                aux_no.chaves.append(r)
                aux_no.filhos.append(self)
                aux_no.filhos.append(nova_folha)
                self.pai = aux_no
                nova_folha.pai = aux_no
                return aux_no
            else:
                return self.pai.inserir(r, nova_folha)
        else:
            folha_proximo = self.folha_proximo
            for chave in self.chaves[index:]:
                for i in range(len(folha_proximo.chaves)):
                    if folha_proximo.chaves[i] > chave:
                        folha_proximo.chaves = folha_proximo.chaves[:i] + [chave] + folha_proximo.chaves[i:]
                        flag = 1
                        break
                if flag == 0:
                    folha_proximo.chaves.append(chave)
            self.chaves = self.chaves[:index]
            n = self.pai
            n.atualizar_chaves()
            while(n.pai != None):
                n = n.pai
            return n
    
    def mesclar(self, folha, ord):
        self.chaves = self.chaves + folha.chaves if ord else folha.chaves + self.chaves
    
    def proximo(self):
        if self.proximo:
            return self.proximo
        else:
            pai = self.pai
            while pai:
                try:
                    index = pai.filhos.index(self)
                    return pai.filhos[index + 1]
                except IndexError:
                    self = pai
                    pai = self.pai
        return None