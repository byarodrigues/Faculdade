# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 17:23:03 2021

@author: Bya
Plote o gráfico e encontre um intervalo 
contendo uma única raiz das seguintes 
funções:
(f) f(x) = x^3 + 3x − 1
"""

import numpy as np
import matplotlib.pyplot as plot

def f(x):
    return x**3 + 3*x -1

interval = np.linspace(-20,20)
plot.plot (interval,f(interval), label = 'f(x)')
plot.legend()
plot.grid ()
plot.show()
