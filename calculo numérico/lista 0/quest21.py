# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:42:53 2021

@author: Bya
A função shuffle() da biblioteca random permite embaralhar uma lista de elementos. Utilizando essa
função crie um código capaz de sortear elementos de uma lista. O usuário deve informar o número 
total de elementos e quantos elementos devem ser sorteados.
"""
import random as rd

total = int(input('Deseja sortear o número de 1 à: '))
qtdd = int(input('Quantos números deseja sortear? '))
lista = list(range(1, total+1))
rd.shuffle(lista)
n = -1

while qtdd != 0:
    n = n + 1
    print(lista[n])
    qtdd = qtdd-1