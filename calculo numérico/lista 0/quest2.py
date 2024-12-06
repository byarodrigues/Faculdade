# -*- coding: utf-8 -*-
"""
Created on Tue Jul 13 15:47:14 2021

@author: Bya
Desenvolva um script em Python que calcule a área de um círculo a partir de seu raio (Area = r
2 × π).
"""
import numpy as np

print('inform the radius:')
r = float(input('R: '))
area = np.pi * r ** 2
print('The area is:', area)
