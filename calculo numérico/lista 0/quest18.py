# -*- coding: utf-8 -*-
"""
Created on Fri Jul 23 23:56:47 2021

@author: Bya
Considerando um conjunto A = {1, 2, 3, ..., n} com n informado pelo usuário, crie um código para 
obter os subconjuntos de três elementos contidos em A. Lembre-se que um conjunto não possui 
elementos repetidos.
"""

print ('Informe o número de elementos do conjunto')
n = int(input('n='))

for cont1 in range(n):
    for cont2 in range(cont1+1, n):
        for cont3 in range(cont2+1, n):
            print('{'+
                    '{n1},{n2},{n3})'.format(n1=cont1+1,n2=cont2+1,n3=cont3+1,)
                    +'}')
            