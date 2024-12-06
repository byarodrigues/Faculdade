# -*- coding: utf-8 -*-
"""
Created on Sat Jul 24 00:42:54 2021

@author: Bya
Implemente um código capaz de ordenar os elementos de uma lista. Inicialmente, o código deve 
receber a quantidade de posições e um valor para cada posição. Em seguida, o código deve 
ordenar os elementos da lista utilizando o método bolha2:
• Percorra a lista várias vezes ordenando pares de elementos, até que todos os elementos 
estejam ordenados;
• Observe o exemplo a seguir:
1. Lista inicial desordenada F,O,R,A,O,R,D,E,M
2. Primeira passagem até a última posição
(a) F,O,R,A,O,R,D,E,M F ≯ O não troca
(b) F,O,R,A,O,R,D,E,M O ≯ R não troca
(c) F,O,R,A,O,R,D,E,M R > A troca
(d) F,O,A,R,O,R,D,E,M R > O troca
(e) F,O,A,O,R,R,D,E,M R ≯ R não troca
(f) F,O,A,O,R,R,D,E,M R > D troca
(g) F,O,A,O,R,D,R,E,M R > E troca
(h) F,O,A,O,R,D,E,R,M R > M troca
(i) F,O,A,O,R,D,E,M,R Fim da primeira passagem
3. Segunda passagem até a penúltima posição
(a) F,O,A,O,R,D,E,M,R F ≯ O não troca
(b) F,O,A,O,R,D,E,M,R O > A troca
(c) F,A,O,O,R,D,E,M,R O ≯ O não troca
(d) F,A,O,O,R,D,E,M,R O ≯ R não troca
(e) F,A,O,O,R,D,E,M,R R > D troca
(f) F,A,O,O,D,R,E,M,R R > E troca
(g) F,A,O,O,D,E,R,M,R R > M troca
(h) F,A,O,O,D,E,M,R,R Fim da segunda passagem
4. Terceira passagem até a antepenúltima posição
(a) F,A,O,O,D,E,M,R,R F > A troca
(b) A,F,O,O,D,E,M,R,R F ≯ O não troca
(c) A,F,O,O,D,E,M,R,R O ≯ O não troca
(d) A,F,O,O,D,E,M,R,R O > D troca
(e) A,F,O,D,O,E,M,R,R O > E troca
(f) A,F,O,D,E,O,M,R,R O > M troca
(g) A,F,O,D,E,M,O,R,R Fim da terceira passagem
5. Quarta passagem até a quarta última posição
(a) A,F,O,D,E,M,O,R,R A ≯ F não troca
(b) A,F,O,D,E,M,O,R,R F ≯ O não troca
(c) A,F,O,D,E,M,O,R,R O > D troca
(d) A,F,D,O,E,M,O,R,R O > E troca
(e) A,F,D,E,O,M,O,R,R O > M troca
(f) A,F,D,E,M,O,O,R,R Fim da quara passagem
6. Quinta passagem até a quinta última posição
(a) A,F,D,E,M,O,O,R,R A ≯ F não troca
(b) A,F,D,E,M,O,O,R,R F > D troca
(c) A,D,F,E,M,O,O,R,R F > E troca
(d) A,D,E,F,M,O,O,R,R F ≯ M não troca
(e) A,D,E,F,M,O,O,R,R Fim da quinta passagem
7. Na sexta passagem não ocorre nenhuma troca e o código pode parar
"""

def bolha2(lista):
    for passagem in range(len(lista)-1,0,-1):
        for i in range(passagem):
            if lista[i]>lista[i+1]:
                temp = lista[i]
                lista[i] = lista[i+1]
                lista[i+1] = temp
informe = input('Informe os elementos a ser ordenados (separado com espaços): ')
lista = [str(x) for x in informe.split()]

bolha2(lista)
print(lista)
                                               