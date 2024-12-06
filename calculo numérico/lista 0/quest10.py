# -*- coding: utf-8 -*-
"""
Created on Thu Jul 15 14:20:20 2021

@author: Bya
Elabore um código que receba três notas
considerando os pesos 0, 3, 0, 3 e 0, 4
para as notas 1, 2 e 3, respectivamente. 
A nota final é soma ponderada das três notas 
(NotaFinal = Nota1 ∗ 0.3 + Nota2 ∗ 0.3 +
Nota3 ∗ 0.4). O código deve receber estas 
notas para 10 alunos. É necessário informar 
se cada aluno foi aprovado (nota final maior 
ou igual a 60) ou não. Também deve ser 
informada a média final de todas as notas 
finais.
"""
notafim = 0
lista_alunos = []
total = 0
print('Informe a nota dos alunos:')
for cont in range(10):
    print('---------------')
    print('nota do aluno ', cont+1)
    n1 = float(input('nota 1:'))
    n2 = float(input('nota 2:'))
    n3 = float(input('nota 3:'))
    
    notafim = n1*0.3 + n2*0.3 + n3*0.4
    total = total + notafim  
    
    if notafim >= 60:
        print('aluno aprovado com nota igual a:', notafim)
    else:
        print('aluno reprovado com nota igual a:', notafim)
    
    lista_alunos.append(notafim)

media = total / 10
print('-------------------------------')
print('A média das notas foi {m:.2f}'.format(m=media))
