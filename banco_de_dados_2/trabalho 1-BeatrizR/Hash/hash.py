from bucket import Bucket
from bucket import No
'''
Implementação com as funções para inicialização, inserção, 
busca, remoção e atualização quando ocorre overflow
'''
class Hash:
    def __init__(self, tamanho_inicial):
        self.tamanho_inicial = tamanho_inicial
        self.to_closed = False
        for i in range(0, tamanho_inicial, 1):
            self.tabela.append(Bucket())
    '''
    Calcula o valor do hash
    '''
    def hash(self, chave):
        return chave%self.tamanho_inicial
    
    '''     
    Busca uma chave em toda a tabela hash
    '''
    def buscar(self, chave):
        hashcode = self.hash(chave)
        aux = Bucket()
        if self.tabela[hashcode].bucket.proximo != 0 and self.tabela[hashcode].bucket.proximo.chave == chave:
            return self.tabela[hashcode].bucket.proximo.chave
        else:
            i = self.hash(hashcode)
            aux = Bucket()  
            procurado = aux.bucket.proximo       
            while i == hashcode:
                if aux.bucket.proximo !=0  and aux.bucket.proximo.chave == chave:
                    return self.tabela[hashcode].bucket.proximo
                i = self.hash(i + 1)
            return 0
    '''
    Insere no hash percorrendo até achar o "apontado pro 
    proximo" para armazenar, se tiver overflow deve chamar
    a função atualiza_inserir
    '''
    def inserir(self, chave, valor):
        hashcode = self.hash(chave)
        print('Inserindo a chave {x} e valor {y}'.format(x = hashcode, y = valor))
        if not self.to_closed:
            if self.tabela[hashcode].bucket.proximo == 0:
                self.tabela[hashcode].inserir(chave, valor, hashcode)
                return
            else:
                if self.tabela[hashcode].bucket.proximo.chave == chave:
                    raise Exception('Erro ao inserir')
                i = self.hash(hashcode + 1)
                while i != hashcode:
                    if self.tabela[i].bucket.proximo == 0:
                        self.tabela[i].inserir(chave, valor, hashcode)
                        return
                    else:
                        if self.tabela[i].bucket.proximo.chave == chave:
                            raise Exception('Erro ao inserir')
                    i = self.hash(i + 1)
                self.atualiza_inserir()
                self.to_closed = True
        else:
            self.tabela[hashcode].inserir(chave, valor, hashcode)
    '''
    Remove a chave e atualiza o apontador caso seja necessáro
    '''
    def remover(self, chave):
        hashcode = self.hash(chave)
        print('Removendo a chave:', chave)
        if not self.to_closed:
            if self.tabela[hashcode].bucket.proximo != 0 and self.tabela[hashcode].bucket.proximo.chave == chave:
                elemento = self.tabela[hashcode].bucket.proximo
                self.tabela[hashcode].bucket.proximo = 0
                return elemento
            else:
                i = self.hash(hashcode + 1)
                while i != hashcode:
                    if self.tabela[i].bucket.proximo != 0 and self.tabela[i].bucket.proximo.chave == chave:
                        elemento = self.tabela[i].bucket.proximo
                        self.tabela[i].bucket.proximo = 0
                        return elemento
                    i = self.hash(i + 1)
                return 0
        else:
            return self.tabela[hashcode].remover(chave) 
    '''
    Divide o bucket quando acontece um overflow
    '''
    def atualiza_inserir(self):
        i = 0
        for j in range(0, self.tamanho_inicial, 1):
            if self.tabela[j].bucket.proximo != 0 and self.tabela[j].bucket.proximo.hashcode == i:
                temp = self.tabela[j].bucket.proximo
                self.tabela[j].remover(temp.chave)
                self.tabela[i].inserir(temp.chave, temp.valor, temp.hashcode)
        i = self.hash(i + 1)
        while i != 0:
            for j in range(0, self.tamanho_inicial, 1):
                if self.tabela[j].bucket.proximo != 0 and self.tabela[j].bucket.proximo.hashcode == i:
                    temp = self.tabela[j].bucket.proximo
                    self.tabela[j].remover(temp.chave)
                    self.tabela[i].inserir(temp.chave, temp.valor, temp.hashcode)
            i = self.hash(i + 1)