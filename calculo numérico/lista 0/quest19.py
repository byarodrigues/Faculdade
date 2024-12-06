# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:02:07 2021

@author: Bya
Considere a lista X exibida na Figura 1. Considere também as variáveis A = 2 e B = 3, informe o
resultado de cada expressão:
(a) X[A + 1]
(b) X[A ∗ 2]
(c) X[A + B]
(d) X[A ∗ B]
(e) X[A] + X[B]
(f) X[X[A] + B]
(g) X[X[X[A + B]]]
(h) X[X[A] ∗ 2]
(i) X[X[A] + X[B]]

40 5 4 10 104 2 23 65 78 974
0 1 2 3 4 5 6 7 8 9 
"""

lista = [40, 5, 4, 10, 104, 2, 23, 65, 78, 974]
a = int(2)
b = int(3)
print('Qual operação deseja fazer?')
oper = int(input('1, 2, 3, 4, 5, 6, 7, 8, 9: '))

cont = 0 

if oper == 1:
    cont = a+1
    print(lista[cont])
    
elif oper == 2:
    cont = a*2
    print(lista[cont])
    
elif oper == 3:
    cont =  a+b
    print(lista[cont])

elif oper == 4:
    cont = a*b
    print(lista[cont])

elif oper == 5:
    print(lista[a]+lista[b])

elif oper == 6:
    ref = lista[a]
    cont = ref + b
    print(lista[cont])

elif oper == 7:
    ref = a+b
    ref2 = lista[ref]
    cont = lista[ref2]
    print(lista[cont])

elif oper == 8:
    ref = lista[a]
    cont = ref*2
    print(lista[cont])

elif oper == 9:
    ref = lista[a]
    ref2 = lista[b]
    cont = ref + ref2
    if cont < 9:
        print(lista[cont])
    else:
        print('Operação inválida')
    


