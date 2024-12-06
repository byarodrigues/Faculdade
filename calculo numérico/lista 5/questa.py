# -*- coding: utf-8 -*-
"""
Created on Tue Aug 17 14:15:20 2021

@author: bya

Utilize o método do ponto fixo para calcular a raiz aproximada das seguintes 
equações. Considere um número máximo de 20 iterações, e' < 10−5.
(a) f(x) = ln(x), intervalo [0.1, 2]
"""

import numpy as np

def f(x):
    return np.log(x)

def g(x):
    return x - 0.5 * f(x)

x=1.7; print('k, x, g2(x), f(x)')
for k in range(5):
    gx=g(x); xa=x; x=g(x)
    print('{k}, {x:.5f}, '.format(k=k+1, x=xa) +
          '{gx:.5f}'.format(gx=gx))

def bissecao(a, b, tol, n):
    x = (a + b) / 2
    xant = float('nan')
    for i in range(1,n):
        x = g(x)
        fx = f(x)
        error=abs((x-xant)/max(x, 1))
        xant = x
        print('It. {i:3d}:'.format(i=i), 'a={a:+.6f},'.format(a=a),
                 'b={b:+.6f},'.format(b=b), 'error={e:+.6f},'.format(e=error),
                 'x={x:+.6f},'.format(x=x), 'f(x)={fx:+.6f},'.format(fx=fx))
        if (fx == 0) or (error < tol):
            print('Raiz aproximada encontrada: {r:+.6f}'.format(r=x))
            break

bissecao(0.1, 2, 0.00001, 20)
