# -*- coding: utf-8 -*-
"""
Created on Wed Sep  8 19:58:47 2021

@author: beatr
Utilize o método Newton-Raphson para calcular a raiz aproximada das seguintes 
equações. Considere um número máximo de 20 iterações, e < 10−5.
(j) f(x) = x − 3 − x^−x, intervalo [2, 4]
"""
import numpy as np

def f(x):
    return x - 3 - x**(-x)

def fant(x):
    return (np.log(x) *x + x**x +1)/x**x

def bissecao(a, b, tol, n):
    x = (a+b)/2
    xant = float('nan')
    fx = f(x)
    for i in range(1,n):
        error=abs((x-xant)/max(x, 1))
        print('It. {i:3d}:'.format(i=i), 'a={a:+.6f},'.format(a=a),
                 'b={b:+.6f},'.format(b=b), 'x={x:+.6f},'.format(x=x))
        if (fx == 0) or (error < tol):
            break
        xant = x
        x = x - (f(x)/fant(x))
        
bissecao(2, 4, 0.00001, 20)