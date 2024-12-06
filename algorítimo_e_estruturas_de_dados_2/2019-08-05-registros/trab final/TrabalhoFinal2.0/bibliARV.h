#ifndef BIBLIARV_H_INCLUDED
#define BIBLIARV_H_INCLUDED
#include "bibliLISTAVACAS.h"
#include <fstream>
#include <iostream>
#include "bibliFILA.h"
#include "structsbibli.h"
using namespace std;
struct TNo {
    TVacas vaca;
    TNo *esq;
    TNo *dir;
};
struct TArvoreBin{
    string nome;
    int contItens;
    TNo *raiz;
};
void criaArvVazia(TArvoreBin &a,string n);
void inserirArv(TArvoreBin &a,TNo *&no,TVacas x);
int lendoArq(string nomeArq, int quantTokens,TArvoreBin &a);
void pesquisar(TArvoreBin a, string c, TNo *&n);
void relRaca(TNo *&no,string r);
void inserindoFila(TNo *&no,TFilaP &f);

#endif // BIBLIARV_H_INCLUDED
