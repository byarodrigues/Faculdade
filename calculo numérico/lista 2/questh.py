# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 17:23:03 2021

@author: Bya
Plote o gráfico e encontre um intervalo 
contendo uma única raiz das seguintes 
funções:
(h) f(x) = 'e'^x − x^2 − 10
"""

import numpy as np
import matplotlib.pyplot as plot
import math as math

def f(x):
    return math.e**x-x**2-10

interval = np.linspace(-1,25)
plot.plot (interval,f(interval), label = 'f(x)')
plot.legend()
plot.grid ()
plot.show()
