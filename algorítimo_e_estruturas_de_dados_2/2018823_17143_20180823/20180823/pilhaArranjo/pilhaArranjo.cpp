/*
    Aula: 23 de Agosto de 2018
    Versão: 1
    Finalidade: demonstrar a implementação do TAD PILHA Linear por Arranjo, baseado
    na implementação de Ziviani
    Autor: Gabriel da Silva
*/

#include <iostream>
#include <clocale>
using namespace std;

// TAD LISTA POR ARRANJO

const int tam = 5; // define a quantidade de elementos

// Estrutura da Lista
struct TPilhaArranjo{
    int vetNum[tam]; // suporte para os itens
    int fundo;
    int topo;
};

// OPERAÇÕES

void criarPilha(TPilhaArranjo &p){
    p.fundo = 0;
    p.topo = p.fundo;
}

bool estaCheia(TPilhaArranjo p){
    if (p.topo >= tam){
        return true;
    }
    else{
        return false;
    }
}

bool estaVazia(TPilhaArranjo p){
    return p.fundo == p.topo;
}

void empilhar(TPilhaArranjo &p, int item){
    if (!estaCheia(p)){
        p.vetNum[p.topo] = item;
        p.topo++;
    }
    else{
        cout << "Não cabe mais nada fiote!" << endl;
    }
}

void desempilhar(TPilhaArranjo &p){
    if (estaVazia(p)){
        cout << "Nada para tirar. Pilha vazia!" << endl;
    }
    else{
        p.topo--;
    }
}

void mostrar(TPilhaArranjo p){
    if (estaVazia(p)){
        cout << "Nada para mostrar. Pilha vazia!" << endl;
    }
    else{
        for (int i=p.topo-1;i>=p.fundo;i--){
            cout << "Pos. " << i << ": " << p.vetNum[i] << endl;
        }
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");
    // usando!!!
    TPilhaArranjo pilha;

    criarPilha(pilha);

    desempilhar(pilha);

    empilhar(pilha,5);
    empilhar(pilha,8);
    empilhar(pilha,7);
    empilhar(pilha,2);

    mostrar(pilha);

    empilhar(pilha,1);

    empilhar(pilha,9);

    mostrar(pilha);

    return 0;
}





