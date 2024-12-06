# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 17:23:03 2021

@author: Bya
Plote o gráfico e encontre um intervalo 
contendo uma única raiz das seguintes 
funções:
(g) f(x) = x^2 + sin x
"""

import numpy as np
import matplotlib.pyplot as plot
import math as math

def f(x):
    return x**2 + math.sin(x)

interval = np.linspace(-20,20)
plot.plot (interval,f(interval), label = 'f(x)')
plot.legend()
plot.grid ()
plot.show()
