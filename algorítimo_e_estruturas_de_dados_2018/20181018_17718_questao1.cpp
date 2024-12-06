#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

//DECLARAÇÕES
const int maxTam = 10;

struct TItem{
    int numero;
};

struct TListaA{
    TItem vetItens[maxTam];
    int primeiro, ultimo;
};



// OPERAÇÕES
void criarListaA(TListaA &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}

bool estaVaziaLA(TListaA l){
    return l.primeiro == l.ultimo;
}

bool estaCheiaLA(TListaA l){
    return l.ultimo >= maxTam;
}

void inserirNormal(TItem item, TListaA &l){
    if (estaCheiaLA(l)){
        cout << "Lista Cheia!" << endl;
    }
    else{
        l.vetItens[l.ultimo] = item;
        l.ultimo++;
    }
}

void realocarItens(string sentido,int pos,TListaA &l){
    if (sentido == "ed"){
        for (int j=pos;j<l.ultimo;j++){
               l.vetItens[j] = l.vetItens[j+1];
        }
    }
    else{
        for (int j=l.ultimo;j>=pos;j--){
               l.vetItens[j] = l.vetItens[j-1];
        }
    }
}

void inserirCrescente(TItem item, TListaA &l){
    if (estaCheiaLA(l)){
        cout << "Lista Cheia!" << endl;
    }
    else{
        if (estaVaziaLA(l)){
            cout << "inserindo normal" << endl;
            inserirNormal(item,l);
        }
        else{
            int pos = l.ultimo;
            for (int i=l.primeiro;i<l.ultimo;i++){
                if (item.numero < l.vetItens[i].numero){
                    pos = i;
                    break;
                }
            }
            realocarItens("de",pos,l);
            l.vetItens[pos] = item;
            l.ultimo++;
        }
    }
}

void retirarNormal(int p,TListaA &l){
    if (estaVaziaLA(l)){
        cout << "Nada para retirar. Lista Vazia." << endl;
    }
    else{
        realocarItens("ed",p,l);
        l.ultimo--;
    }
}

void mostrarLA(TListaA l){

    cout << "--------- MOSTRAR ----------" << endl;
    if (estaVaziaLA(l)){
        cout << "Lista Vazia. Nada para mostrar!" << endl;
    }
    else{
        for (int i=l.primeiro;i<l.ultimo;i++){
            cout <<"Item " << i << ": " << l.vetItens[i].numero << endl;
        }
    }
}

//void mostrarLAG(TListaAGrande l){
//
//    cout << "--------- MOSTRAR ----------" << endl;
//    if (estaVaziaLA(l)){
//        cout << "Lista Vazia. Nada para mostrar!" << endl;
//    }
//    else{
//        for (int i=l.primeiro;i<l.ultimo;i++){
//            cout <<"Item " << i << ": " << l.vetItens[i].numero << endl;
//        }
//    }
//}

void copiarLista(TListaA l1,TListaA &l2){
    l2 = l1;
}

void concatenarListas(TListaA l1, TListaA l2, TListaA &l3){

    for (int i=l1.primeiro;i<l1.ultimo;i++){
        //l3.vetItens[i] = l1.vetItens[i]; // ISTO É UM ABSURDO!!!
        inserirNormal(l1.vetItens[i],l3);
    }
    //int desloc = l1.ultimo;
    for (int i=l2.primeiro;i<l2.ultimo;i++){
        //l3.vetItens[i+desloc] = l2.vetItens[i];// ISTO É UM ABSURDO!!!
        inserirNormal(l2.vetItens[i],l3);
    }
}

int main(){

    TListaA lista1, lista2, lista3, lista4;

    criarListaA(lista1);
    TItem iAux;

    iAux.numero = 5;
    inserirCrescente(iAux,lista1);
    iAux.numero = 4;
    inserirCrescente(iAux,lista1);
    iAux.numero = 7;
    inserirCrescente(iAux,lista1);
    iAux.numero = 2;
    inserirCrescente(iAux,lista1);
    iAux.numero = 9;
    inserirCrescente(iAux,lista1);

    mostrarLA(lista1);

    retirarNormal(2,lista1);

    mostrarLA(lista1);

    criarListaA(lista2);
    copiarLista(lista1, lista2);

    mostrarLA(lista2);

    criarListaA(lista3);

    concatenarListas(lista1,lista2,lista3);
    mostrarLA(lista3);
    cout << "Ultimo da l3: " << lista3.ultimo << endl;

    iAux.numero = 14;
    inserirNormal(iAux,lista3);
    iAux.numero = 15;
    inserirNormal(iAux,lista3);
    iAux.numero = 16;
    inserirNormal(iAux,lista3);
        mostrarLA(lista3);


    return 0;
}
