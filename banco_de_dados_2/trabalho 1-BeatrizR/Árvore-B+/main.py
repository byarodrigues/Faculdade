from arvorebm import Arvore 
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
    cont = 0
    
    try:
        with open(args.file) as arquivo:
            linhas = csv.reader(arquivo)
            for linha in linhas:
                if linha[0] == '+':
                    arvore.inserir(linha[1])
                    cont += 1
                if linha[0] == '-':
                    arvore.deletar(linha[1])
                    cont += 1
    except IOError as x:
        print(x.strerror)
 
    opcao = True
    while opcao:
        print ('''
          _____________________________
          |  1.Inserir                |
          |  2.Deletar                |
          |  3.Busca por igualdade    |
          |  4.Busca por intervalo    |
          |  5.Sair                   |
          |___________________________|
        ''')
        opcao = input("Escolha uma opção: ") 
        print ('''
          _______________
        ''')
        if opcao=="1":
            valor = int(input("Informe um valor: "))
            arvore.inserir(valor)
            print ('''
                _______________
            ''')
        elif opcao=="2":
            valor = int(input("Informe um valor: "))
            arvore.remove(valor)
            print ('''
                _______________
            ''')
        elif opcao=="3":
            valor = int(input("Informe um valor: "))         
            print ("Valor encontrado") if arvore.buscar_por_igualdade(valor, arvore.raiz) != 0 else print("Valor não encontrado")
            print ('''
                _______________
            ''')
        elif opcao=="4":
            valor1 = int(input("Informe o valor 1: "))         
            valor2 = int(input("Informe o valor 2: "))         
            print ("Valor encontrado") if arvore.buscar_intervalo(valor1, valor2, pagina=arvore.raiz) != 0 else print("Valor não encontrado")
            print ('''
                _______________
            ''')
        elif opcao=="5":
            print("Saindo...")
            opcao = False
        elif opcao !="":
            print("Opção inválida")
    return 0

if __name__ == '__main__':
    sys.exit(main())