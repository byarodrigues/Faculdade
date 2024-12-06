#include <iostream>
/*
Você está preso dentro de um castelo com N quartos e M corredores. Os quartos são numerados com números entre 1 e N e você está inicialmente no quarto número 1. Cada um dos M corredores conecta dois quartos distintos. Para tentar sair, você decidiu visitar todos os N quartos do castelo.

Todos os quartos, com exceção do quarto número 1 onde você está, precisam de uma chave para serem visitados. Você teve sorte em encontrar algumas notas no chão, dizendo onde todas essas chaves estão. Por exemplo, sejam S e D dois quartos distintos, para visitar o quarto D você precisa primeiro visitar o quarto S que tem a chave para abrir o quarto S.

Com a informação sobre os quartos, corredores e localização das chaves, descubra se é possível visitar todos os quartos do castelo.

Entrada
Haverá no máximo 70 casos de teste. Cada caso de teste começa com dois inteiros N e M, indicando o número de quartos e corredores do castelo (2 ≤ N ≤ 103, 1 ≤ M ≤ 104).

Em seguida haverá M linhas contendo dois inteiros A e B cada, indicando que há um corredor que conecta o quarto A e B, que pode ser percorrido em ambas as direções (1 ≤ A, B ≤ N).

Em seguida haverá N-1 inteiros k2, k3, …, kN, indicando que no quarto ki você pode encontrar a chave para abrir o quarto i (1 ≤ ki ≤ N, para todos 2 ≤ i ≤ N). Observe que não há quarto que contenha a chave para o quarto número 1, porque este é o primeiro quarto onde você está e está aberto.

A entrada termina com o final do arquivo (EOF).
Saída
Se for possível visitar todos os quartos do castelo, imprima a palavra "sim", caso contrário, imprima a palavra "não".

*/
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
