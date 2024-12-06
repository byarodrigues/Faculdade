#ifndef BIBLILISTAVACAS_H_INCLUDED
#define BIBLILISTAVACAS_H_INCLUDED
#include <iostream>
#include "bibliARV.h"
#include <stdio.h>
#include "structsbibli.h"
using namespace std;
struct TlistaVacas{
    TCelula *primeiro;
    TCelula *ultimo;

};
void criarListaVazia(TlistaVacas &l);
bool listaVazia(TlistaVacas l);
void inserir(TlistaVacas l,TlistaVacas l2);
int escreverArq(TlistaVacas l);
int lendoArqLista(string nomeArq, int quantTokens,TlistaVacas &l);
void ordenaLista(TlistaVacas &l);
void mostrarLista(TlistaVacas l);
void inserirLista2(TlistaVacas &l,TVacas x);
bool verificaLista(string cd,TlistaVacas l2);



#endif // BIBLILISTAVACAS_H_INCLUDED
