#include <iostream>
#include "bibTadLinear.h"

using namespace std;


// OPERAÇÕES
void criarListaVazia(TListaA &l){
    l.primeiro = 0;
    l.ultimo = 0;
    cout << "Lista criada com sucesso!" << endl;
}

bool estaVazia(TListaA l){
    return l.primeiro == l.ultimo; //Ziviani
    //return l.ultimo == 0; // Rener!
}

bool estaCheia(TListaA l){
    return l.ultimo >= 10;
}

void inserir(TItem item, TListaA &l){
    if (estaCheia(l)){
        cout << "Não posso armazenar. Lista cheia!" << endl;
    }
    else{
        l.vetItens[l.ultimo] = item;
        l.ultimo++;
    }
}

int contaItens(TListaA l){
    return l.ultimo;
}

void mostrarItens(TListaA l){

    for (int i=l.primeiro;i<l.ultimo;i++){
        cout << "Posição " << i << ": " << l.vetItens[i].valor << endl;
    }
}

