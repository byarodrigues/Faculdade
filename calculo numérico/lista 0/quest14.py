# -*- coding: utf-8 -*-
"""
Created on Fri Jul 23 22:30:11 2021

@author: Bya
Implemente o algoritmo de Euclides1 para 
calcular o máximo divisor comum (MDC) de 
dois números.
"""

print('Informe dois números:')
n1 = int(input('N1:'))
n2 = int(input('N2:'))

if n1 < 1 or n2 < 1:
    print('Números inválidos!!')
else:
    r = n1 % n2
    while r != 0:
        n1 = n2
        n2 = r
        r = n1 % n2
print('O MDC é ', n2)
