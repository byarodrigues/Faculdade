# -*- coding: utf-8 -*-
"""
Created on Fri Jul 23 23:46:59 2021

@author: Bya
Desenvolva um código que, considerando um conjunto de números naturais A = {1, 2, 3, ..., n}, 
gere todas as combinações com três elementos contidos em A. Antes de gerar as combinações o 
programa deve perguntar o número de elementos de A ao usuário.
"""

n = int(input('Informe o número de elementos do conjunto: '))

for cont1 in range(n):
    for cont2 in range(n):
        for cont3 in range(n):
            print('({n1},{n2},{n3})'.format(n1=cont1+1,n2=cont2+1,n3=cont3+1,))
            