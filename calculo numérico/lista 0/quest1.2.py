# -*- coding: utf-8 -*-
"""
Created on Tue Jul 13 17:00:20 2021

@author: Bya
Escreva um código que receba um número de segundos e converta este número em horas, minutos e
segundos. Escreva também um programa que faça o contrário.
"""

print('complete:')
sec = float(input('seconds:'))
min = float(input('minutes:'))
hrs = float(input('hours:'))

seconds = sec
minutes = min * 60
hours = hrs * 3600
results = seconds + minutes + hours
print(hrs, 'hours,', min, 'minutes and', sec, 'seconds are:', round(results,1), 'seconds')
