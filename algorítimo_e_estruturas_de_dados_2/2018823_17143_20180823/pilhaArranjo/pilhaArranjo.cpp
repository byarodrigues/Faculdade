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

 // define a quantidade de elementos
struct Titem{
 int chave;
};
// Estrutura da Lista
struct TPilhaA{
    int vetNum[tam]; // suporte para os itens
    int fundo;
    int topo;
};

// OPERAÇÕES

void criarPilha(TPilhaArranjo &p){
    p.fundo = -1;
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
    return p.topo == -1;
}

void empilhar(TPilhaArranjo &p, Titem x){
    if (estaCheia(p)){
        cout << "Não cabe mais nada fiote!" << endl;
    }
    else{
        p.topo++;
        p.vetNum[p.topo] = item;
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
            cout << "Pos. " << i << ": " << p.vetNum[i].chave << endl;
        }
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");
    // usando!!!
    TPilhaA pilha;

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





