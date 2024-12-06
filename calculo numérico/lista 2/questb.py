# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 17:23:03 2021

@author: Bya
Plote o gráfico e encontre um intervalo 
contendo uma única raiz das seguintes 
funções:
(b) f(x) = math.e^x
"""

import numpy as np
import matplotlib.pyplot as plot
import math as math

def f(x):
    return math.e**x

interval = np.linspace(18,25)
plot.plot (interval,f(interval), label = 'f(x)')
plot.legend()
plot.grid ()
plot.show()
