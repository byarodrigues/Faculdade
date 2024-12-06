#include <iostream>
#include "bibliLISTAVACAS.h"
#include "bibliARV.h"
#include "interface.h"
#include "bibliFILA.h"
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");
    TArvoreBin arvore;
    TlistaVacas lista,lista2;
    TFilaP fila;
    criaArvVazia(arvore,"vacas");
    criarListaVazia(lista);
    criarListaVazia(lista2);
    criarFilaPVazia(fila);
    menu(lista,arvore,fila,lista2);
    return 0;
}
