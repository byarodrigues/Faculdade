"""
@author: beatr
"""
import numpy as np

def f(x, funcao):
    fun = funcao
    return eval(fun)

def g(x,fun):
    return x - 0.5 * f(x,fun)

def pontofixo(a, b, tol, n, fun):
    x = (a + b) / 2
    xant = float('nan')
    for i in range(1,n):
        x = g(x, fun)
        fx = f(x, fun)
        error=abs((x-xant)/max(x, 1))
        xant = x
        print('It. {i:3d}:'.format(i=i), 'a={a:+.6f},'.format(a=a),
                 'b={b:+.6f},'.format(b=b), 'error={e:+.6f},'.format(e=error),
                 'x={x:+.6f},'.format(x=x), 'f(x)={fx:+.6f},'.format(fx=fx))
        if (fx == 0) or (error < tol):
            print('Raiz aproximada encontrada: {r:+.6f}'.format(r=x))
            break

