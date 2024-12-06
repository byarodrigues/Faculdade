from arvorebmais import Arvore
import matplotlib.pyplot as plt
import time
import os
import sys
import argparse
import csv

FILE_DEFAULT = 'output.csv'

def main():

    parser = argparse.ArgumentParser(description='Trabalho Banco de Dados II')
    parser.add_argument('--file', "-f",required = False, default=FILE_DEFAULT, help= "Arquivo de entrada")
     
    args = parser.parse_args()
    
    arvore = Arvore(3)
    
    y = []
    tempo = []
    cont = 0
    
    try:
        with open(args.file) as arquivo:
            linhas = csv.reader(arquivo)
            for linha in linhas:
                if linha[0] == '+':
                    arvore.inserir(linha[1])
                    cont += 1
                    y.append(cont)
                    tempo.append(time.time())
                if linha[0] == '-':
                    arvore.deletar(linha[1])
                    cont += 1
                    y.append(cont)
                    tempo.append(time.time())
    except IOError as x:
        print(x.strerror)
        
    plt.plot(y, tempo)
    plt.grid(True)
    plt.title('Árvore B+')
    plt.xlabel('x (Inserções e Remoções)')
    plt.ylabel('y (Tempo)')
    plt.show()
    
    return 0
 
if __name__ == '__main__':
    sys.exit(main())