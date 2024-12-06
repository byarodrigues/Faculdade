# -*- coding: utf-8 -*-
"""
Created on Wed Jul 14 18:38:56 2021

@author: Bya
Considere a função range(início, fim, passo).
Utilize essa função algumas vezes com
variações nos parâmetros e faça laços
de repetições para imprimir os valores
gerados.
"""
print('write the terms:')
st = int(input('Start:'))
end = int(input('The end:'))
pas = int(input('Passo:'))

lista = []

for i in range(end):
    lista.append(i)
    print(lista)

lista = []

for i in range(st,end):
    lista.append(i)
    print(lista)

lista = []

for i in range(st,end,pas):
    lista.append(i)
    print(lista)
    
    

