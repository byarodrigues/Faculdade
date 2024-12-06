# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:52:25 2021

@author: Bya
Implemente um módulo com as seguintes funções:
ano_bissexto(ano): retorna True se o ano for bissexto e False, em caso negativo;
dias_mes(ano, mes): retorna a quantidade de dias do mês (deve usar a função ano_bissexto);
nome_mes(mes): retorna o nome do mes informado (1 a 12)
Construa um programa que receba uma data do usuário (mês e ano) e mostre o resultado das funções
implementadas sobre essa data.
"""

def ano_bissexto(x):
    if x%400 == 0:
        print('Esse é um ano bissexto')
        return 0
    else:
        if x%4 == 0 and not x%100 == 0:
            print('Esse é um ano bissexto')
            return 0
        else:
            print('Esse não é um ano bissexto')

def dias_mes(x1,x2):
    if x1 == 1:
        return 31
    elif x1 == 2:
        if x2 == 0:
            return 28
        else:
            return 29
    elif x1 == 3:
        return 31
    elif x1 == 4:
        return 30
    elif x1 == 5:
        return 31
    elif x1 == 6:
        return 30
    elif x1 == 7:
        return 31
    elif x1 == 8:
        return 31
    elif x1 == 9:
        return 30
    elif x1 == 10:
        return 31
    elif x1 == 11:
        return 30
    elif x1 == 12:
        return 31
        
def nome_mes(x1):
    if x1 == 1:
        return 'janeiro'
    elif x1 == 2:
        return 'fevereiro'
    elif x1 == 3:
        return 'março'
    elif x1 == 4:
        return 'abril'
    elif x1 == 5:
        return 'maio'
    elif x1 == 6:
        return 'junho'
    elif x1 == 7:
        return 'julho'
    elif x1 == 8:
        return 'agosto'
    elif x1 == 9:
        return 'setembro'
    elif x1 == 10:
        return 'outubro'
    elif x1 == 11:
        return 'novembro'
    elif x1 == 12:
        return 'dezembro'
        
ano = int(input('Qual o ano? '))
ano_bissexto(ano)
mes = int(input('Qual o do mês?(1 a 12) '))
print('O mes de',nome_mes(mes), 'do ano de', ano, 'teve', dias_mes(mes, ano), 'dias')
