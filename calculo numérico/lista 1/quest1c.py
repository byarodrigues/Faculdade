# -*- coding: utf-8 -*-
"""
Created on Fri Aug  6 00:41:18 2021

@author: Bya
(c) 1010010.0112 para as bases 4, 8, 10, 16
"""

n = 82.375
n_int = int(n)
bin_int=''
while n_int > 0:
    resto = n_int % 4
    bin_int = str(resto) + bin_int
    n_int = n_int // 4
n_frac = n - int(n)
bin_frac = ''
for cont in range(8):
    n_frac *= 4
    bin_frac += str(int(n_frac))
    n_frac -= int(n_frac)
    if n_frac == 0:
        break
print(bin_int + '.' + bin_frac)

n = 82.375
n_int = int(n)
bin_int=''
while n_int > 0:
    resto = n_int % 8
    bin_int = str(resto) + bin_int
    n_int = n_int // 8
n_frac = n - int(n)
bin_frac = ''
for cont in range(8):
    n_frac *= 8
    bin_frac += str(int(n_frac))
    n_frac -= int(n_frac)
    if n_frac == 0:
        break
print(bin_int + '.' + bin_frac)

def d_hexa(n):
    if n == 10:
        return 'A'
    elif n == 11:
        return 'B'
    elif n == 12:
        return 'C'
    elif n == 13:
        return 'D'
    elif n == 14:
        return 'E'
    elif n == 15:
        return 'F'
    return str(n)

n = 82.375
n_int = int(n)
bin_int=''
while n_int > 0:
    resto = n_int % 16
    bin_int = d_hexa(resto) + bin_int
    n_int = n_int // 16
n_frac = n - int(n)
bin_frac = ''
for cont in range(8):
    n_frac *= 16
    bin_frac += d_hexa(int(n_frac))
    n_frac -= int(n_frac)
    if n_frac == 0:
        break
print(bin_int + '.' + bin_frac)
