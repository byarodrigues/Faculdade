# -*- coding: utf-8 -*-
"""
Created on Tue Aug 17 14:14:28 2021

@author: bya

Utilize o método da posição falsa para calcular a raiz aproximada das seguintes 
equações. Considere um número máximo de 20 iterações e e' < 10−5.
(a) f(x) = ln(x), intervalo [0.1, 3]
"""

import numpy as np

def f(x):
    return np.log(x)

def bissecao(a, b, tol, n):
    xant = float('nan')
    for i in range(1,n):
        x = (a*f(b)) - (b*f(a)) / (f(b) - f(a))
        fx = f(x)
        sinal = f(a) * fx
        error=abs((x-xant)/max(x, 1))
        xant = x
        print('It. {i:3d}:'.format(i=i), 'a={a:+.6f},'.format(a=a),
                 'b={b:+.6f},'.format(b=b), 'error={e:+.6f},'.format(e=error),
                 'x={x:+.6f},'.format(x=x), 'f(x)={fx:+.6f},'.format(fx=fx),
                 'sinal={s:+.6f}'.format(s=sinal))
        if (fx == 0) or (error < tol):
            print('Raiz aproximada encontrada: {r:+.6f}'.format(r=x))
            break
        if sinal > 0:
            a = x
        else:
            b = x

bissecao(0.1, 3, 0.00001, 20)
