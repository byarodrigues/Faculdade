# -*- coding: utf-8 -*-
"""
Created on Tue Jul 13 19:05:16 2021

@author: Bya
Considere a fórmula para cálculo de juros simples:
J = (C × I × T) / 100 , onde J, C, I e T correspondem a juros, capital, taxa e tempo, respectivamente. Construa um código
que solicite ao usuário os valores de C, I e T e calcule J.
"""

print('inform the valor to find "juros":')
c = float(input('Capital: '))
i = float(input('Taxa: '))
t = float(input('Tempo: '))

j = (c*i*t) / 100

print('The "Juros" are:', j)
