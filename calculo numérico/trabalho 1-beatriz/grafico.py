# -*- coding: utf-8 -*-
"""
Created on Sat Sep 11 21:32:01 2021

@author: beatr
"""
import numpy as np
import matplotlib.pyplot as pyplot

def f(x, funcao):
    fun = funcao
    return eval(fun)
 
def graf(inte1, inte2, fun):
    intel = np.linspace(inte1, inte2)
    pyplot.plot(intel, f(intel, fun))
    pyplot.grid()
    pyplot.show()


