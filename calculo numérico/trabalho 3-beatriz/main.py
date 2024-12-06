# -*- coding: utf-8 -*-
"""
Created on Mon Sep 13 18:17:07 2021

@author: beatr
O trabalho consiste na implementação de um interpolador. Os seguintes pontos devem ser considerados:

- O programa deve pedir ao usuário para informar os pontos (podendo ser qualquer quantidade de pontos);

- Depois da entrada dos pontos, o sistema deve verificar se os mesmos são válidos;

- Em seguida, o sistema deve calcular o polinômio interpolador utilizando o métodos de Lagrange e/ou o 
método das divididas de Newton;

- Deverá ser entregue um único arquivo contendo códigos e comentários;

- O trabalho é individual, cópias da Internet ou colegas serão desconsideradas
"""
import numpy as np
import newton as new

def main():
    x = []
    y = []
    n = int(input('Informe o número de pontos(1 a 4): '))
    print('\nInforme os "x" de cada ponto')
    for i in range(1):
        lin = input('x{i}: '.format(i=i))
        lin_num = lin.split(',')
        lin_num = [float(i) for i in lin_num]
        x.append(lin_num)
    x = np.array(x, dtype='double')
    
    print('\nInforme os "y" de cada ponto')
    for i in range(1):
        lin = input('y{i}: '.format(i=i))
        lin_num = lin.split(',')
        lin_num = [float(i) for i in lin_num]
        y.append(lin_num)
    y = np.array(y, dtype='double')
    
    new.divididas(x,y,n)
    
main()
