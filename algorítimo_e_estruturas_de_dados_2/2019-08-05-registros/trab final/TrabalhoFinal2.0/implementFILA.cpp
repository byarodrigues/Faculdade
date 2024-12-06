#include "bibliFILA.h"
#include <iostream>
#include "structsbibli.h"
#include "bibliARV.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
void criarFilaPVazia(TFilaP &f){
   f.frente = new TCelula;
   f.tras = f.frente;
   f.frente->proximo = NULL;
   f.contItens = 0;
}
bool estaVazia(TFilaP f){
    return f.frente == f.tras;
}

void enfileirarVacas(TFilaP &f, TVacas x){
    f.tras->proximo = new TCelula;
    f.tras = f.tras->proximo;
    f.tras->vaca = x;
    f.tras->proximo = NULL;
    f.contItens++;
}

void mostrar(TFilaP f){
    TCelula *celAux;
    celAux = f.frente->proximo;
    double aux;
    cout << "               PRODUÇÃO DE LEITE DURANTE A SEMANA!"<< endl;
    if (estaVazia(f)){
        cout << "               Nenhum perfil para mostrar!" << endl;
    }
    else{
        while (celAux != NULL){
            aux =0;
            cout<<"             ID:"<<celAux ->vaca.codigo<<endl;
            for (int z = 0;z < 7;z++){
                    aux = aux + atoi(celAux->vaca.litrosP[z].c_str());
                }
            cout<<"             Litros produzidos: "<<int(aux)<<endl;
            cout<<"             Ração consumida: "<<int(aux/3)<<"KG DE Ração"<<endl;
            cout<<" "<<endl;
            cout<<" "<<endl;
            celAux = celAux->proximo;
        }
    }
}
