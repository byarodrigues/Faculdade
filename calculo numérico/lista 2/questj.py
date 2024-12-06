# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 17:23:03 2021

@author: Bya
Plote o gráfico e encontre um intervalo 
contendo uma única raiz das seguintes 
funções:
(j) f(x) = x − 3 − (x^−x)
"""
import numpy as np
import matplotlib.pyplot as plot

def f(x):
    return x-3-(x**-x)

interval = np.linspace(0,10)
plot.plot (interval,f(interval), label = 'f(x)')
plot.legend()
plot.grid ()
plot.show()
