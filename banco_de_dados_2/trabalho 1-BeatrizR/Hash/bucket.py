class No:
    def __init__(self, chave, valor, hashcode, anterior = 0, proximo = 0):
        self.chave = chave
        self.valor = valor
        self.hashcode = hashcode
        self.anterior = anterior
        self.proximo = proximo

class Bucket:
    def __init__(self):
        self.bucket = No(0, 0, 0)
    
    def buscar(self, chave):
        aux = self.bucket.proximo
        while aux != 0:
            if aux.chave == chave:
                return aux
            aux = aux.proximo
        return 0
    
    def inserir(self, chave, valor, hashcode):
        if self.buscar(chave) == 0:
            no = No(chave, valor, hashcode)
            ultimo_endereco = self.bucket.proximo
            while ultimo_endereco != 0:
                if ultimo_endereco.proximo != 0:
                    ultimo_endereco.proximo = no     
                    no.anterior = ultimo_endereco
                    return
                ultimo_endereco = ultimo_endereco.proximo
            self.bucket.proximo = no
            no.anterior = self.bucket

    def remover(self, chave):
        procurado = self.bucket.proximo
        while procurado != 0:
            if procurado.chave == chave:
                if procurado.proximo == 0:
                    procurado.anterior.proximo = 0
                    procurado.anterior,
                    procurado.proximo = 0
                    return procurado
                else:
                    procurado.anterior.proximo = procurado.proximo
                    procurado.proximo.anterior = procurado.anterior
                    procurado.anterior, 
                    procurado.proximo = 0
                    return procurado
            procurado = procurado.proximo
