# -*- coding: utf-8 -*-
"""
Created on Sat Sep 11 15:03:57 2021

@author: beatr
Utilize o método das secantes para calcular a raiz aproximada das seguintes equações. Considere um
número máximo de 20 iterações, e' < 10−5.
(i) f(x) = √x − cos(x), intervalo [0, 2]
"""
import numpy as np

def f(x):
    return x**(1/2) - np.cos(x)

def secantes(a, b, tol, n):
    x = a
    xl = b
    fx = f(x)
    for i in range(1,n):
        error=abs((x-xl)/max(x, 1))
        print('It. {i:3d}:'.format(i=i), 'error={e:+.6f},'.format(e=error),
                 'x={x:+.6f},'.format(x=x), 'f(x)={fx:+.6f},'.format(fx=fx))
        if (fx == 0) or (error < tol):
            break
        xll = x - f(x)* ((x-xl)/f(x)-f(xl))
        xl = x
        x = xll

secantes(0, 2, 0.00001, 20)
