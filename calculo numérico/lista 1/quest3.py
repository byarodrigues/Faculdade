# -*- coding: utf-8 -*-
"""
Created on Thu Aug  5 13:02:05 2021

@author: Bya
Calcule o erro absoluto e relativo das aproximações:
a) x = 1.00001 e x- = 1
b) x = 100001 e x- = 100000
c) x = 32.65483 e x- = 34.1645
d) x = 5.87135 e x- = 5.87049
"""

def erro_absoluto(num, aprox):
    return abs(num - aprox)

def erro_relativo(num, aprox):
    return abs(num - aprox) / num
lista_num = [1.00001, 100001, 32.65483, 5.87135]
lista_aprox = [1, 100000, 34.1645, 5.87049]

print("Erros Abslotulos")
for cont in range(4):
    num = lista_num[cont]
    aprox = lista_aprox[cont]
    erro = erro_absoluto(num, aprox)
    print("x={x:.8f}, x*={a:.8f},".format(x=num, a=aprox), end=' ')
    print("erro={e:.8f}".format(e=erro))

print("\nErros Relativos")
for cont in range(4):
    num = lista_num[cont]
    aprox = lista_aprox[cont]
    erro = erro_relativo(num, aprox)
    print("x={x:.8f}, x*={a:.8f},".format(x=num, a=aprox), end=' ')
    print("erro={e:.8f}".format(e=erro))