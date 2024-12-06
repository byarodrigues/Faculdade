# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 17:23:03 2021

@author: Bya
Plote o gráfico e encontre um intervalo 
contendo uma única raiz das seguintes 
funções:
(c) f(x) = cos x
"""

import numpy as np
import matplotlib.pyplot as plot

def f(x):
    return np.cos(x)

interval = np.linspace(-4,4)
plot.plot (interval,f(interval), label = 'f(x)')
plot.legend()
plot.grid ()
plot.show()
