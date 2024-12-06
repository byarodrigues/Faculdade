# -*- coding: utf-8 -*-
"""
Created on Tue Jul 20 14:17:34 2021

@author: Bya

Projete um código que leia uma quantidade indeterminada de números. 
A cada número informado, o usuário deve informar se deseja continuar
ou parar. Ao final, o código deve retornar o maior e o menor número recebido.
"""

n = int(input('Informe um número: '))
maior = n 
menor = n

while True:
    resp = input('Deseja continuar? (S/N) ')
    if resp.lower() == 'n':
        break
    n = int(input('Informe um número: '))
    if n > maior:
        maior = n
    if n < menor:
        menor = n
        
print('Maior número: ', maior)
print('Menor número: ', menor)
