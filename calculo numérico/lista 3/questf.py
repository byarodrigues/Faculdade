# -*- coding: utf-8 -*-
"""
Created on Mon Aug 16 22:08:11 2021

@author: Bya
Utilize o método da bisseção para encontre
a raiz aproximada das seguintes equações.
Considere um número máximo de 20 iterações,
'e' < 10−5 e os intervalos dados.

(f) f(x) = x^3 + 3x − 1, intervalo [−5, 5]
"""

def f(x):
    return x**3 + 3*x - 1

def bissecao(a, b, tol, n):
    xant = float('nan')
    for i in range(n):
        x = (a + b) / 2
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

bissecao(-5, -5, 0.00001, 20)
