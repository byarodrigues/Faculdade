from hash import Hash
from bucket import Bucket
import sys
import argparse
import csv

ARQUIVO_PADRAO = 'output.csv'
TAMANHO_INICIAL = 3

def main():

    '''abrindo um arquivo com o tamanho passado'''
    parser = argparse.ArgumentParser(description='Indice Hash')
    parser.add_argument('--file', "-f",required = False, default=ARQUIVO_PADRAO, help= "Arquivo de entrada")
    parser.add_argument('--tamanho', "-t",required = False, type=int, default=TAMANHO_INICIAL, help= "Tamanho inicial")
     
    args = parser.parse_args()    
    hash = HashMap(args.tamanho)
    cont = 0
    '''lê os dados do arquivo'''
    try:
        with open(args.file) as arquivo:
            linhas = csv.reader(arquivo)
            for linha in linhas:
                if linha[0] == '+':
                    hash.inserir(int(linha[1]), int(linha[1]))
                    cont += 1
                if linha[0] == '-':
                    hash.remover(int(linha[1]))
                    cont += 1
    except IOError as x:
        print(x.strerror)

    opcao = True
    while opcao:
        print ('''
          _______________
          |  1.Inserir  |
          |  2.Deletar  |
          |  3.Buscar   |
          |  4.Sair     |
          |_____________|
        ''')
        opcao = input("Escolha uma opção: ") 
        print ('''
          _______________
        ''')
        if opcao=="1":
            valor = int(input("Informe um valor: "))
            hash.inserir(valor, valor)
            print ('''
                _______________
            ''')
        elif opcao=="2":
            valor = int(input("Informe um valor: "))
            hash.remover(valor)
            print ('''
                _______________
            ''')
        elif opcao=="3":
            valor = int(input("Informe um valor: "))         
            print ("Valor encontrado") if hash.buscar(valor) != 0 else print("Valor não encontrado")
            print ('''
                _______________
            ''')
        elif opcao=="4":
            print("Saindo...")
            opcao = False
        elif opcao !="":
            print("Opção inválida")
    return 0

if __name__ == '__main__':
    sys.exit(main())