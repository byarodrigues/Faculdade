# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:52:26 2021

@author: Bya
Selecione alguns dos códigos desenvolvidos e os execute passa a passo observando o fluxo de 
execução e os valores das variáveis.
"""

#Escolhi um pronto ja e observei...
#Percebi od fluxos de valores das variáveis
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