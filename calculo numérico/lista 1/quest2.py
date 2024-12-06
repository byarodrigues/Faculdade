# -*- coding: utf-8 -*-
"""
Created on Thu Aug  5 13:02:03 2021

@author: Bya
Aproxime os números a seguir para três dígitos significativos por arredondamento e por truncamento:
(a) 1.1598
(b) 7.3999
(c) −5.9012
(d) 1.1615
(e) 3.135598
(f) 8.394559
(g) −9.907142
(h) 0.1615221
"""

lista_num = [1.1598, 7.3999, -5.9012, 1.1615,

3.135598, 8.394559, -9.907142, 0.1615221]

print('Arredondamento')
for num in lista_num:
    print(round(num, 3))
print('\nTruncamento')
for num in lista_num:
    num2 = int(num*10**3) / 10**3
    print(num2)