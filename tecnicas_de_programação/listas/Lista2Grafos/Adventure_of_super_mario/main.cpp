#include <iostream>
/*
Super Mario precisa encontrar um caminho de volta para casa depois de resgatar a princesa linda. Ele conhece muito bem o "Super Mario World", então não precisa de um mapa, ele só precisa do melhor caminho para economizar tempo.
Existem A Aldeias e B Castelos no mundo. As aldeias são numeradas de 1 a A, e os castelos são numerados de A+1 a A+B. Mario mora na Aldeia 1 e o castelo no qual ele começa é numerado A+B. Além disso, existem estradas de duas mãos conectando-os. Dois lugares são conectados por, no máximo, uma estrada e um lugar nunca tem uma estrada se conectando a si mesmo. Mario já mediu o comprimento de cada estrada, mas eles não querem andar o tempo todo, pois ele caminha uma unidade de tempo por uma unidade de distância (quão devagar!).

Felizmente, no castelo onde ele salvou a princesa, Mario encontrou um sapato mágico. Se ele o usar, pode correr super de um lugar a outro SEM TEMPO. (Não se preocupe com a princesa, Mario encontrou uma maneira de levá-la com ele quando corre super, mas ele não contaria para você :-P).

Como existem armadilhas nos castelos, Mario NUNCA corre super através de um castelo. Ele sempre para quando há um castelo no caminho. Além disso, ele começa/para correr super APENAS em aldeias ou castelos.

Infelizmente, o sapato mágico é muito velho, então ele não pode usá-lo para cobrir mais de L quilômetros de uma só vez e não pode usá-lo mais de K vezes no total. Quando ele volta para casa, pode tê-lo consertado e torná-lo utilizável novamente.

Entrada
A primeira linha da entrada contém um único inteiro T, indicando o número de casos de teste (1 ≤ T ≤ 20). Cada caso de teste começa com cinco inteiros A, B, M, L e K - o número de vilarejos, o número de castelos (1 ≤ A, B ≤ 50), o número de estradas, a distância máxima que pode ser percorrida de uma vez (1 ≤ L ≤ 500), e o número de vezes que a bota pode ser usada (0 ≤ K ≤ 10). As próximas M linhas cada contém três inteiros Xi, Yi, Li. Isso significa que há uma estrada conectando os lugares Xi e Yi. A distância é Li, então o tempo de caminhada também é Li (1 ≤ Li ≤ 100).

Saída
Para cada caso de teste na entrada, imprima uma linha contendo um único inteiro indicando o tempo mínimo necessário para ir para casa com a bela princesa. É garantido que o Super Mario sempre pode ir para casa.
*/
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
