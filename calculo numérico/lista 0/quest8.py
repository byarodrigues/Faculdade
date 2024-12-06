# -*- coding: utf-8 -*-
"""
Created on Wed Jul 14 18:30:00 2021

@author: Bya
Crie um código que receba valores para as variáveis reais A, B e C e calcule a seguinte fórmula

N = (A + B × C) − √(A × B × C) / (2 × C + B)
"""
import numpy as np

a = float(input('A:'))
b = float(input('B:'))
c = float(input('C:'))

n = ((a+b*c)-(np.sqrt(a*b*c))) / (2*c+b)
print('the result is:', n)
