#include <iostream>
#include "bibTadLinear.h"

using namespace std;

void criarListaVazia(TListaA &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}

bool estaVazia(TListaA l){
    return l.primeiro == l.ultimo;
}

bool estaCheia(TListaA l){
    return l.ultimo >= 10;
}

void inserir(int x, TListaA &l){
    if(estaCheia(l)){
        cout << "A lista está cheia. Não posso inserir." << endl;
    }
    else{
        l.valor[l.ultimo] = x;
        l.ultimo++;
    }
}

void mostrar(TListaA l){

    cout << "=== MOSTRANDO ITENS DA LISTA===" << endl;
    for(int i=l.primeiro;i<l.ultimo;i++){
        cout << "Pos " << i << ": " << l.vetItens[i] << endl;
    }
}

void retirarPos(TListaA &l, int p){
    int aux;

    if((estaVazia(l)) || (p>=l.ultimo) || (p<l.primeiro)){
        cout << "Não posso retirar! Lista vazia ou posição fora do limite" << endl;
    }
    else{
       l.ultimo--;
       for(aux=p;aux<l.ultimo;aux++){
            l.vetItens[aux] = l.vetItens[aux+1];
       }
    }
}

int buscarChave(TListaA l, int c){
    bool achou = false;
    int pegaPos;

    if (estaVazia(l)){
        return -1;
    }
    else{
        for(int i=l.primeiro;i<l.ultimo;i++){
            if(l.vetItens[i]== c){
                achou = true;
                pegaPos = i;
                break;
            }
        }
        if(achou == true){
            return pegaPos;
        }
        else{
            return -1;
        }
    }
}
