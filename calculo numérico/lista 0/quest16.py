# -*- coding: utf-8 -*-
"""
Created on Fri Jul 23 23:25:27 2021

@author: Bya
Elabore um código capaz de simular uma 
calculadora simples. O código deve solicitar 
ao usuário a operação desejada (soma, 
multiplicação, divisão, subtração ou potência)
ou então sair. Quando o usuário escolhe uma 
operação, o programa deve solicitar dois 
números, realizar a operação sobre estes 
números e exibir o resultado. O código deve 
sempre solicitar uma nova operação até que o 
usuário escolha sair.
"""

while True:
    print('Informe a operação desejada ou (sair) para sair')
    print('Para adicionar (a)')
    print('Para subitrair (s)')
    print('Para multiplicar (m)')
    print('Para dividir (d)')
    print('Para elevar (e)')
    print('Para raiz (r)')
    resposta = input()
    if resposta == 'sair':
        break
    if resposta not in ['a','s','m','d','e','r']:
        print('(OPÇÃO INVÁLIDA)')
    else:
        print('Informe dois números')
        n1 = float(input('N1:'))
        n2 = float(input('N2:'))
        if resposta == "a":
            r = n1 + n2
        elif  resposta == "s":
            r = n1 - n2
        elif  resposta == "m":
            r = n1 * n2
        elif  resposta == "d":
            r = n1 / n2
        elif  resposta == "e":
            r = n1 ** n2
        elif resposta == "r":
            r = n1**(1/n2)
        print ('O resutado da operação foi: ',r)
    