# -*- coding: utf-8 -*-
"""
Created on Wed Jul 14 18:19:34 2021

@author: Bya
Faça um código para determinar se um ano é ou não bissexto. Um ano N é bissexto se N é múltiplo de
400, ou então se N é múltiplo de quatro, mas não é múltiplo de 100. Por exemplo, 2012 (múltiplo de 4,
mas não múltiplo de 100) é bissexto, 1900 (múltiplo de quatro e de 100) não é bissexto, 2000 (múltiplo
de 400) é bissexto).
"""
n = float(input('write a year:'))
if n%400 == 0:
    print('this is a leap year')
else:
    if n%4 == 0 and not n%100 == 0:
        print('This is a leap year')
    else:
        print('This is not a leap year')
        