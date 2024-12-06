# -*- coding: utf-8 -*-
"""
Created on Fri Jul 23 23:06:51 2021

@author: pc
Crie um código que calcule o mínimo múltiplo 
comum (MMC) entre dois números. O MMC de dois
números n1 e n2 pode ser calculado como MMC =
n1∗n2 
MDC , onde MDC é o máximo divisor comum entre
n1 e n2.
"""

def mdc(n1,n2):
    r = n1 % n2
    while r != 0:
        n1 = n2
        n2 = r
        r = n1 % n2
    return n2

print('Informe dois numeros')
n1 = int(input('N1:'))
n2 = int(input('N2:'))

if n1 < 1 or n2 < 1:
    print('Números inválidos')
else:
    mmc = (n1*n2)// mdc(n1,n2)
    print('O mmc é ', mmc)