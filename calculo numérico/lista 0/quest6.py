# -*- coding: utf-8 -*-
"""
Created on Tue Jul 13 19:53:01 2021

@author: Bya
Faça um código capaz de calcular as raízes de uma equação de segundo grau no formato Ax2+Bx+C = 0.
Considere as seguintes observações:
• Se o termo A = 0 então a equação não é uma equação de segundo grau;
• Seja ∆ = B2 − 4 × A × C. Se ∆ < 0 então a equação não possui raízes. Se ∆ = 0 então a equação
possui apenas uma raiz.
"""

import numpy as np
print('Inforthe terms:')
a = float(input('A:'))
b = float(input('B:'))
c = float(input('C:'))

if a == 0:
    print('This is not a quadratic equation!')
else:
    delta = b**2 - 4*a*c
    if delta < 0:
        print('This equation have not an raiz')
    else:
        x1 = (-b + np.sqrt(delta)) / (2*a)
        if delta == 0:
            print('the only raiz is:', x1)
        else:
            x2 = (-b - np.sqrt(delta)) / (2*a)
            print('Yours raizs are:')
            print('x1 =', x1)
            print('x2 =', x2)
   