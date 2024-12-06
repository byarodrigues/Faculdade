#ifndef BIBTADLINEAR_H_INCLUDED
#define BIBTADLINEAR_H_INCLUDED

using namespace std;

// DEFINIÇÃO DO TAD TLISTA-ARRANJO

// ESTRUTURA

struct TItem{
    int valor;
};

struct TListaA{
    TItem vetItens[10];
    int primeiro;
    int ultimo;
};

// OPERAÇÕES
void criarListaVazia(TListaA &l);

bool estaVazia(TListaA l);

//bool estaCheia(TListaA l);

void inserir(TItem item, TListaA &l);

int contaItens(TListaA l);

void mostrarItens(TListaA l);


#endif // BIBTADLINEAR_H_INCLUDED
