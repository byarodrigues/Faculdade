# -*- coding: utf-8 -*-
"""
Created on Tue Jul 13 14:26:56 2021

@author: Bya
Escreva um código que receba um número de segundos e converta este número em horas, minutos e
segundos. Escreva também um programa que faça o contrário.
"""

sec = float(input('write the seconds: '))

hr = sec//3600
rest = sec % 3600
min = rest//60
restmin = sec % 60
if restmin >= 60:
   seconds = restmin/60
else:
   seconds = restmin 
print(sec, 'seconds are:', round(hr,1), 'hours,', round(min,1), 'minutes and', round(seconds,1), 'seconds.' )
