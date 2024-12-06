# -*- coding: utf-8 -*-
"""
Created on Thu Jul 22 23:37:32 2021

@author: Bya
Elabore um código que calcule o fatorial de 
um número recebido. O fatorial de um número n,
representado por n!, é calculado da seguinte 
maneira n! = n × (n − 1) × ... × 2 × 1. 
Sendo que 1! = 0! = 1.
"""

def ftr (x):
    if x <= 1:
        return 1
    else:
        return x*ftr(x-1) 
n = int(input('Qual número deseja fatorar? '))
fatorado = ftr(n)
print('O fatorial de ', n, 'é ', fatorado)