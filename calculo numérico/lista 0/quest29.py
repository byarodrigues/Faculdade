# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:52:26 2021

@author: Bya
Escreva um módulo com funções para calcular o máximo divisor comum (MDC) e o mínimo múltiplo
comum (MMC) de uma lista de números. Dica: comece calculando o MDC dos dois primeiros números e,
depois, para cada número, calcule o MDC desse número com o resultado anterior (o MMC pode ser feito
de fórmula análoga). Implemente também chamadas a essas funções números digitados pelo usuário.
"""

def funcoes(x1,x2):
    if x1 < 1 or x2 < 1:
        print('Números inválidos!!')
    else:
        r = x1 % x2
        while r != 0:
            x1 = x2
            x2 = r
            r = x1 % x2
    print('O MDC é', x2)
    mmc = (x1*x2)// x2
    print('O MMC é?' , mmc)    
    
num1 = int(input('Informe o número 1: '))
num2 = int(input('Informe o número 2: '))

funcoes(num1, num2)
