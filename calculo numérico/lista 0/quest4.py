# -*- coding: utf-8 -*-
"""
Created on Tue Jul 13 19:14:26 2021

@author: Bya
Construa um código que receba três números e informe o maior deles.
"""

n1 = float(input('write the first number:'))
n2 = float(input('write the next:'))
n3 = float(input('write the next:'))

big = n1
if n2 > big:
    big = n2

if n3 > big: 
    big = n3

print('The bigest number is:', big)
