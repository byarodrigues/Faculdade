# -*- coding: utf-8 -*-
"""
Created on Thu Jul 22 22:46:57 2021

@author: Bya
A fórmula C = 5/9 (F − 32) representa a 
equivalência de temperaturas entre graus 
Celsius (C) e graus Fahrenheit (F). 
Construa um código capaz de converter uma 
temperatura de Celsius para Fahrenheit e 
outro que façam o contrário (F = 9/5C + 32). 
Junte os dois códigos de conversão em um 
único código. Inicialmente deve ser 
perguntado ao usuário qual a conversão 
desejada para que em seguida seja usada
a fórmula adequada.
"""
print('Qual operação pretende fazer?')
print('Digite (0) se quiser achar os graus Celsius a partir do Fahrenheit: ')
print('Digite (1) se quiser achar os graus Fahrenheit a partir do Celsius: ')

resp = int(input('Resposta: '))
c = 0
f = 0

if resp == 0:
    f = float(input('Digite os graus Fahrenheit:'))
    c = (f-32)*5/9
    print('O resultado foi ', c, 'graus Celsius')

if resp == 1:
    c = float(input('Digite os graus Celsius:'))
    f = (c*9)/5 + 32
    print('O resultado foi ', f, 'graus Fahrenheit')
   
