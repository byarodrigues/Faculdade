# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 17:23:03 2021

@author: Bya
Plote o gráfico e encontre um intervalo 
contendo uma única raiz das seguintes 
funções:
(e) f(x) = 'e'^(2−(x^2)) × (x + 1)^2
"""

import numpy as np
import matplotlib.pyplot as plot
import math as math

def f(x):
    return math.e**(2-(x**2))*(x+1)**2

interval = np.linspace(-5,5)
plot.plot (interval,f(interval), label = 'f(x)')
plot.legend()
plot.grid ()
plot.show()
