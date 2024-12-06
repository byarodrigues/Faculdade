# -*- coding: utf-8 -*-
"""
Created on Mon Sep 13 18:15:18 2021

@author: beatr
O trabalho consiste na implementação de um resolvedor sistemas lineares. Os seguintes pontos devem 
ser considerados:

- O programa deve solucionar sistemas lineares com n vaiáveis e n equações;

- A implementação deve solicitar ao usuário todas as informações do sistema (número de variáveis, 
  matriz estendida do sistema, tolerância e número máximo de iterações);

- Após a entrada dos dados, o programa deve mostrar o sistema para que o usuário possa conferir e 
  confirmar se deseja prosseguir;

- Depois da confirmação, o resolvedor deve fazer um pivotamento na matriz estendida (isto evita erros 
  quando a diagonal principal possui zeros). Nesta etapa, você deve verificar se o sistema possui solução. 
  Lembrando que o sistema não tem solução se, após o pivotamento, restarem zeros na diagonal principal;

- Em seguida, utilize o critério do raio espectral para testar se o sistema original convergirá;

- Por fim, o programa deve calcular a solução utilizando um método iterativo;

- Deverá ser entregue um único arquivo contendo códigos e comentários;

- O trabalho é individual, cópias da Internet ou colegas serão desconsideradas.
"""
import numpy as np
import raioespectral as rai
import iteracao as it
import pivotamento as piv

def matriz():
    M = []
    n = int(input('Informe o número de variáveis do sistema: '))
    print('Informe a matriz estendida do sistema (linha por linha)')
    for i in range(n):
        lin = input('Linha {i}: '.format(i=i))
        lin_num = lin.split(',')
        lin_num = [float(i) for i in lin_num]
        M.append(lin_num)
    M = np.array(M, dtype='double')
    return M

def main():
    
    toler = input('Qual a tolerância que pretende usar para os métodos?') # pega a tolerancia a ser usada
    numint = input('Qual o número máximo de iterações que pretende usar para os métodos?') #pega o numero maximo de interações a ser usada
    
    print(matriz())
    resp = input('Essa é a matriz a ser calculada? S/N')
    if(resp == 'S' or 's'):
        it.iteracao(float(toler), float(numint), matriz())
        piv.pivotamento(float(toler), float(numint), matriz())
        rai.raio()
    elif(resp == 'N' or 'n'):
        print('Sistema finalizado')
        
main()
