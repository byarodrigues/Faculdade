# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:52:25 2021

@author: Bya
Implemente o módulo mat.py contendo as seguintes funções:
impar(numero): Retorna True ou False, caso o numero seja impar ou não;
area_circulo(raio): retorna a área de um círculo a partir de seu raio, área = raio2 × π (dica, importe
pi da biblioteca math)
Codifique as chamadas a essas funções em outro arquivo.
"""
import numpy as np

def mat(x1):
    if x1%2 == 0:
        print('Esse número é par')
    else:
        print('Esse número é ímpar ')

    
def area_circulo(x2):
    area = np.pi * x2 ** 2
    print('The area is:', area)

raio = int(input('Informe o raio:'))
area_circulo(raio)
numero = int(input('Informe um número: ')) 
mat(numero)
    
            