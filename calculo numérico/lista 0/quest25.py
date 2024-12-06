# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:52:24 2021

@author: Bya
Desenvolva um código que receba uma lista de números inteiros e, sem seguida, crie uma nova lista
contendo os mesmos números sem repetições.
"""
informe = input('Informe a lista de números (separado com espaços): ')
lista = [str(x) for x in informe.split()]

def removendo_repetidos(lista):

  lista2 = []
  for x in lista:
    if(x in lista2):
      pass 
    else:
      lista2.append(x)
  return lista2

lista = (removendo_repetidos(lista))

print('A lista sem numeros repetidos é: ', lista)
