# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 17:23:03 2021

@author: Bya
Plote o gráfico e encontre um intervalo 
contendo uma única raiz das seguintes 
funções:
(d) f(x) = x^2 + 2x + 1
"""

import numpy as np
import matplotlib.pyplot as plot

def f(x):
    return x**2 + 2*x +1

interval = np.linspace(-20,20)
plot.plot (interval,f(interval), label = 'f(x)')
plot.legend()
plot.grid ()
plot.show()
