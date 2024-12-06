#ifndef BIBTADLINEAR_H_INCLUDED
#define BIBTADLINEAR_H_INCLUDED

using namespace std;

struct TListaA{
    int valor;
    int primeiro;
    int ultimo;
};

void criarListaVazia(TListaA &l);

bool estaVazia(TListaA l);

bool estaCheia(TListaA l);

void inserir(TItem item, TListaA &l);

int contaItens(TListaA l);

void retirarPos(TListaA &l, int p);

int buscarChave(TListaA l, int c);

void mostrar(TListaA l);


#endif
