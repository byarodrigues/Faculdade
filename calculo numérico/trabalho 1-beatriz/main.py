"""
@author: beatr
O trabalho consiste na implementação de um sistema de resolução de equações não lineares. 
Os seguintes pontos devem ser considerados:

- O programa deve, inicialmente, receber uma equação e um intervalo para plotar o gráfico;

- Em seguida, o usuário poderá ajustar o intervalo até que decida calcular a raiz da equação;

- Quando o usuário confirmar o intervalo, o sistema deve calcular a raiz utilizando os métodos estudados;

- Pelo menos três métodos devem ser implementados;

- Deverá ser entregue um único arquivo contendo códigos e comentários;

- O trabalho é individual, cópias da Internet ou colegas serão desconsideradas.
"""
import grafico as gra
import bissecao as bi
import posicaofalsa as pfa
import pontofixo as pfi

def main():

    funcao = input('Insira uma função seguindo a linguagem python: ') # pegando a função a ser calculada
    inte1 = input('Insira o primeiro número do intervalo: ') # pega o primeiro número do intervalo
    inte2 = input('Insira o segundo número do intervalo: ') # pega o segundo número do intervalo

    print('Aqui está o gráfico dessa função: ')    
    gra.graf(float(inte1), float(inte2), funcao)

    print('Agora escolha um método para calcular a raiz')
    resposta = int(input('Insira (1) para método da bisseção, (2) para método da posição falsa e (3) para método do ponto fixo '))

    if(resposta == 1):
        bi.bissecao(float(inte1), float(inte2), 10**-5, 20, funcao) # coloquei 10**-5 e 20 como padrao pois foi usado nas listas
    elif(resposta == 2):
        pfa.posicaofalsa(float(inte1), float(inte2), 10**-5, 20, funcao)
    elif(resposta == 3):
        pfi.pontofixo(float(inte1), float(inte2), 10**-5, 20, funcao)
    print('Operação finalizada, Obrigada')

main()
