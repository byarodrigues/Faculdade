# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:42:54 2021

@author: Bya
Construa um código capaz de calcular a velocidade média de uma viagem a partir das velocidades de
cada trecho. Uma viagem pode possuir de 1 a 50 trechos. O cálculo da velocidade média n trechos é
dado pela fórmula:

distância1 × velocidade1 + ... + distâncian × velocidaden

distância1 + ... + distâncian

Após o cálculo da velocidade média, o programa deve exibir quais trechos tiveram velocidade acima 
da média.
"""
listaVel = []
listaDis = []

trechos = input('Quantos trechos teve?(de 1 à 50): ')
reserva = int(trechos)
reserva1 = int(trechos)
reserva2 = int(trechos)
reserva3 = int(trechos)

while reserva != 0:
    listaVel.append(input('Qual a velocidade? '))
    listaDis.append(input('Qual a distancia? '))
    reserva -= 1

i = 0
distot = int(0)
while reserva1 != 0:
    distot += int(listaDis[i])
    reserva1 -= 1
    i += 1

i = 0
disxvel = int(0)
while reserva2 != 0:
    disxvel += (int(listaDis[i])*int(listaVel[i]))
    reserva2 -= 1
    i += 1

vmedia = int(disxvel/distot)
print('A média foi... ', vmedia)

i = 0
while reserva3 != 0:
    if vmedia < int(listaVel[i]):
        print('O trecho', i+1, 'foi maior do que a média')
    reserva3 -= 1
    i += 1
