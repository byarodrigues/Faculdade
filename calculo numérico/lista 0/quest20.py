# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:42:53 2021

@author: Bya
Implemente um código que receba duas listas com 10 números e armazene em um terceira lista a soma
das duas primeiras, considerando as respectivas posições. Ao final, exiba o resultado na tela.
"""
informe1 = input('Informe uma lista de 10 números separados com espaço: ')
lista1 = [int(x) for x in informe1.split()]

informe2 = input('Informe uma segunda lista de 10 números separados com espaço: ')
lista2 = [int(x) for x in informe2.split()]

num0 = lista1[0]+lista2[0]
num1 = lista1[1]+lista2[1]
num2 = lista1[2]+lista2[2]
num3 = lista1[3]+lista2[3]
num4 = lista1[4]+lista2[4]
num5 = lista1[5]+lista2[5]
num6 = lista1[6]+lista2[6]
num7 = lista1[7]+lista2[7]
num8 = lista1[8]+lista2[8]
num9 = lista1[9]+lista2[9]

lista3 = [num0, num1, num2, num3, num4, num5, num6, num7, num8, num9]

print('A soma dessas listas deram:', lista3)