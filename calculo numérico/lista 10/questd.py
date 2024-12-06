# -*- coding: utf-8 -*-
"""
Created on Mon Sep 13 18:11:06 2021

@author: beatr
Encontre o polinômio interpolador para os seguintes conjuntos de pontos utilizando os métodos de
Lagrange e das divididas de Newton.
(d) {(−6, 4),(4, 9),(9, 0),(17, −7)}
"""
import numpy as np

#Divididas de Newton em Python

print('-----------------------------------------------')
print('\n------- Divididas de Newton em Python ---------\n')

x = np.array([-6, 4, 9, 17], dtype='double')
y = np.array([4, 9, 0, -7], dtype='double')

T = np.zeros((4, 4))

T[:,0] = y
print('\nPrimeira coluna:\n', T)

T[1,1] = (T[1,0] - T[0,0])/(x[1] - x[0])
T[2,1] = (T[2,0] - T[1,0])/(x[2] - x[1])
T[3,1] = (T[3,0] - T[2,0])/(x[3] - x[2])
print('\nSegunda coluna:\n', T)

T[2,2] = (T[2,1] - T[1,1])/(x[2] - x[0])
T[3,2] = (T[3,1] - T[2,1])/(x[3] - x[1])
print('\nTerceira coluna:\n', T)

T[3,3] = (T[3,2] - T[2,2])/(x[3] - x[0])
print('\nQuarta coluna:\n', T)

print('-----------------------------------------------')
print('\nPolinômios menores:')
pm0 = np.poly1d(1)
print(pm0)
pm1 = np.poly1d([1, -x[0]])
print(pm1)
pm2 = np.poly1d([1, -x[1]])
print(pm2)
pm3 = np.poly1d([1, -x[2]])
print(pm3)

p0 = pm0
print('-----------------------------------------------')
print('\np0:\n', p0)

print('-----------------------------------------------')
p1 = np.polymul(pm1, p0)
print('\np1:\n', p1)
print('-----------------------------------------------')
p2 = np.polymul(pm2, p1)
print('\np2:\n', p2)

print('-----------------------------------------------')
p3 = np.polymul(pm3, p2)
print('\np3:\n', p3)

p0 = np.polymul(p0, T[0,0])
print('-----------------------------------------------')
print('\np0*a1:\n', p0)

p1 = np.polymul(p1, T[1,1])
print('-----------------------------------------------')
print('\np1*a2:\n', p1)

p2 = np.polymul(p2, T[2,2])
print('-----------------------------------------------')
print('\np2*a3:\n', p2)

p3 = np.polymul(p3, T[3,3])
print('-----------------------------------------------')
print('\np3*a4:\n', p3)

p = p0 + p1 + p2 + p3
print('-----------------------------------------------')
print('\nPolinômnio Interpolador:\n', p)


#Método de Langrange em Python

print('-----------------------------------------------')
print('\n------- Método de Langrange em Python ---------\n')

# Denominador
d = (x[0] - x[1])*(x[0] - x[2])*(x[0] - x[3])
# Numerador
px1 = np.poly1d([1, -x[1]])
px2 = np.poly1d([1, -x[2]])
px3 = np.poly1d([1, -x[3]])
px = np.polymul(px1, px2)
px = np.polymul(px, px3)
l0 = np.polydiv(px, d)[0]
print('-----------------------------------------------')
print('L0:\n', l0)

d = (x[1] - x[0])*(x[1] - x[2])*(x[1] - x[3])
px1 = np.poly1d([1, -x[0]])
px2 = np.poly1d([1, -x[2]])
px3 = np.poly1d([1, -x[3]])
px = np.polymul(px1, px2)
px = np.polymul(px, px3)
l1 = np.polydiv(px, d)[0]
print('-----------------------------------------------')
print('L1:\n', l1)

d = (x[2] - x[0])*(x[2] - x[1])*(x[2] - x[3])
px1 = np.poly1d([1, -x[0]])
px2 = np.poly1d([1, -x[1]])
px3 = np.poly1d([1, -x[3]])
px = np.polymul(px1, px2)
px = np.polymul(px, px3)
l2 = np.polydiv(px, d)[0]
print('-----------------------------------------------')
print('L2:\n', l2)

d = (x[3] - x[0])*(x[3] - x[1])*(x[3] - x[2])
px1 = np.poly1d([1, x[0]])
px2 = np.poly1d([1, x[1]])
px3 = np.poly1d([1, x[2]])
px = np.polymul(px1, px2)
px = np.polymul(px, px3)
l3 = np.polydiv(px, d)[0]
print('-----------------------------------------------')
print('L3:\n', l0)
p = np.polymul(l0, y[0]) + \
np.polymul(l1, y[1]) + \
np.polymul(l2, y[2]) + \
np.polymul(l3, y[3])
print('-----------------------------------------------')
print('Polinômio Interpolador:\n', p)
