# -*- coding: utf-8 -*-
"""
Created on Thu Aug  5 13:00:12 2021

@author: Bya
(a) Os seguintes números para a base decimal: 425.135 8, 1001101.1101 2 e 12FA7.4C8 16(77735.29882813)

"""

num1 = '425.135'
num2 = '1001101.1101'
num3 = '12FA7.4C8'

def dig_hex(dig):
    if dig.lower() == 'A':
        return 10.0
    elif dig.lower() == 'B':
        return 11.0
    elif dig.lower() == 'C':
        return 12.0
    elif dig.lower() == 'D':
        return 13.0
    elif dig.lower() == 'E':
        return 14.0
    elif dig.lower() == 'F':
        return 15.0
    else:
        return dig

l_partes1 = num1.split('.')
l_partes2 = num2.split('.')
l_partes3 = num3.split('.')
num1_int = (l_partes1[0])
num1_frac = l_partes1[1]
base1 = '8'
bin1_int = ' '

num2_int = l_partes2[0]
num2_frac = l_partes2[1]
base2 = '2'
bin2_int = ' '

num3_int = l_partes3[0]
num3_frac = l_partes3[1]
base3 = '16'
bin3_int = ' '

soma1 = 0.0

for cont in range(len(num1_int)):
    dig = num1_int[-(cont +1)]
    num1_dig = float(dig)
    soma1 += num1_dig*8**cont

for cont in range (len(num1_frac)):
    dig = num1_frac[cont]
    num1_dig = float(num1_frac[cont])
    exp = -(cont + 1)
    soma1 += num1_dig*8**exp

soma2 = 0.0 

for cont in range(len(num2_int)):
    dig = num2_int [-(cont +1)]
    num2_dig = float(dig)
    soma2 += num2_dig*2**cont

for cont in range (len(num2_frac)):
    dig = num2_frac[cont]
    num2_dig = float(num2_frac[cont])
    exp = -(cont + 1)
    soma2 += num2_dig*2**exp

soma3 = 0.0 

for cont in range(len(num3_int)):
    dig = num3_int [-(cont +1)]
    num3_dig = dig_hex(dig)
    soma3 += float(dig_hex(dig))*16**cont

for cont in range (len(num3_frac)):
    dig = num3_frac[cont]
    num3_dig = dig_hex(dig)
    exp = -(cont + 1)
    soma3 += num3_dig*16**exp


print(soma1)
print(soma2) 
print(soma3)