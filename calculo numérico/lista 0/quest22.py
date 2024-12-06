# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:42:54 2021

@author: Bya
Projete um código que preencha uma lista de 100 posições com números de 1 a 10 (utilize a função
randint() da biblioteca random). Em seguida, conte o número de vezes que cada número aparece e
armazene em um segunda lista. Por fim, exiba a quantidade de veses que cada número apareceu.
"""
import random as rd
lista = []
   
for i in range(100):
    lista.append(rd.randint(1,10))
print(lista)
um = 0
dois = 0
tres = 0
quatro = 0
cinco = 0
seis = 0
sete = 0
oito = 0
nove = 0
dez = 0
for i in range(100):
    if lista[i] == 1:
        um = um + 1
    if lista[i] == 2:
        dois = dois + 1
    if lista[i] == 3:
        tres = tres + 1
    if lista[i] == 4:
        quatro = quatro + 1
    if lista[i] == 5:
        cinco = cinco + 1
    if lista[i] == 6:
        seis = seis + 1
    if lista[i] == 7:
        sete = sete + 1
    if lista[i] == 8:
        oito = oito + 1
    if lista[i] == 9:
        nove = nove + 1
    if lista[i] == 10:
        dez = dez + 1
lista2 = [um,dois,tres, quatro, cinco, seis, sete, oito, nove, dez]
print('O número de vezes que apareceram os números foi (em ordem crescednte):', lista2)    
