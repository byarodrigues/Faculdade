/*
    Aula: 23 de Agosto de 2018
    Versão: 1
    Finalidade: demonstrar a implementação do TAD FILA Linear por Arranjo, baseado
    na implementação de Ziviani
    ATENÇÃO: esta versão possui um PROBLEMA na implementação: mesmo
    tirando um item da fila após ela ter sido cheia, não permite
    enfileirar mais nenhum.
    Autor: Gabriel da Silva
*/

#include <iostream>
#include <clocale>
using namespace std;

// TAD LISTA POR ARRANJO

const int tam = 5; // define a quantidade de elementos

// Estrutura da Lista
struct TFilaArranjo{
    int vetNum[tam]; // suporte para os itens
    int frente;
    int tras;
};

// OPERAÇÕES

void criarFila(TFilaArranjo &f){
    f.frente = 0;
    f.tras = f.frente;
}

bool estaCheia(TFilaArranjo f){
    if (f.tras >= tam){
        return true;
    }
    else{
        return false;
    }
}

bool estaVazia(TFilaArranjo f){
    return f.frente == f.tras;
}

void enfileirar(TFilaArranjo &f, int item){
    if (!estaCheia(f)){
        f.vetNum[f.tras] = item;
        f.tras++;
    }
    else{
        cout << "Não cabe mais nada fiote!" << endl;
    }
}

void desenfileirar(TFilaArranjo &f){
    if (estaVazia(f)){
        cout << "Nada para tirar. Fila vazia!" << endl;
    }
    else{
        f.frente++;
    }
}

void mostrar(TFilaArranjo f){
    if (estaVazia(f)){
        cout << "Nada para mostrar. Fila vazia!" << endl;
    }
    else{
        for (int i=f.frente;i<f.tras;i++){
            cout << "Pos. " << i << ": " << f.vetNum[i] << endl;
        }
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");
    // usando!!!
    TFilaArranjo fila;

    criarFila(fila);

    enfileirar(fila,5);
    enfileirar(fila,8);
    enfileirar(fila,7);
    enfileirar(fila,2);

    mostrar(fila);

    enfileirar(fila,9);
    enfileirar(fila,1);

    mostrar(fila);

    desenfileirar(fila);

    mostrar(fila);

    enfileirar(fila,1);

    return 0;
}





