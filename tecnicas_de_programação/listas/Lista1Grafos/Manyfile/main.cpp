#include <iostream>
/*
No ano de 2569, Vasya recebe um ótimo presente de aniversário de sua mãe, o código-fonte de seu jogo de vídeo favorito, Solitaire Spider. Vasya vai direto para o seu computador com 4096 núcleos de processadores, insere o disco, digita ls no diretório do código-fonte e percebe que ele é composto por N arquivos e um Manyfile.

Um Manyfile é algo como uma receita de bolo usada para compilar o código-fonte. Ao digitar o comando many, o Manyfile é lido e os arquivos são compilados, de tal forma que o número máximo de núcleos seja usado simultaneamente. Se tudo estivesse bem, esse processo seria realmente rápido, já que cada arquivo de origem leva exatamente um minuto para ser compilado. No entanto, a compilação de alguns arquivos depende da conclusão de outros, o que pode tornar impossível compilar todos os arquivos simultaneamente.

Considere que a compilação de Solitaire Spider tenha terminado quando todos os N arquivos são compilados. Sabendo em que arquivos os arquivos dependem, escreva um programa que calcule quantos minutos serão necessários para compilar o jogo.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 1000), o número de arquivos de origem de Solitaire Spider. Os arquivos são numerados de 1 a N. As próximas N linhas descrevem os arquivos. A i-ésima linha contém um inteiro Mi (0 ≤ Mi < N) seguido de Mi inteiros entre 1 e N, todos diferentes de i, representando o índice dos arquivos no qual o arquivo i depende.
A entrada termina com fim-de-arquivo (EOF).

Saída
Para cada caso de teste, imprima uma única linha contendo o tempo total, em minutos, que será necessário para compilar Solitaire Spider. Se for impossível compilá-lo, imprima -1.
*/
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
