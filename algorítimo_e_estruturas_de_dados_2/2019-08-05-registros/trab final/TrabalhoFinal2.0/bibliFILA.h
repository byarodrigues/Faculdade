#ifndef BIBLIFILA_H_INCLUDED
#define BIBLIFILA_H_INCLUDED
#include "structsbibli.h"
#include "bibliFILA.h"
using namespace std;
struct TFilaP{
    TCelula *frente;
    TCelula *tras;
    int contItens;
};
void criarFilaPVazia(TFilaP &f);
bool estaVazia(TFilaP f);
void enfileirarVacas(TFilaP &f, TVacas x);
void mostrar(TFilaP f);
#endif // BIBLIFILA_H_INCLUDED
