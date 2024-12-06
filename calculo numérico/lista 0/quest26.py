# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:52:24 2021

@author: Bya
Crie as funções input_int(mensagem) e input_float(mensagem) semelhantes à função input().
As funções devem receber uma mensagem, exibi-la ao usuário e garantir que o número digitado seja
válido. Enquanto o usuário digitar um número incorreto, as funções devem informar que o número é
inválido e solicitar e digitação novamente. Faça uma chamada a cada função para testá-las. Dica: 
utilize a instrução try (tratamento de exceções).
"""

while True:
    try:
        quant = int(input('Informe a quantidade de números: '))
        break
    except:
        print('Número inválido! Tente novamente.')

