"""
@author: beatr
"""
import numpy as np

def f(x, funcao):
    fun = funcao
    return eval(fun)

def posicaofalsa(a, b, tol, n, fun):
    xant = float('nan')
    for i in range(1,n):
        x = (a*f(b, fun)) - (b*f(a, fun)) / (f(b, fun) - f(a, fun))
        fx = f(x,fun)
        sinal = f(a, fun) * fx
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
            
