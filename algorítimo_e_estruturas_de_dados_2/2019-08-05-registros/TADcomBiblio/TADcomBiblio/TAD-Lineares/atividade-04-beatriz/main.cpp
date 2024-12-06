#include <iostream>
#include "bibTadLinear.h"

using namespace std;

int main()
{

    setlocale(LC_ALL,"Portuguese");

//    TListaP lista;
//    criarListaPVazia(lista);
//
//    cout << "EM cel Prim: " << lista.primeiro << endl;
//    cout << "EM cel Ulti: " << lista.ultimo << endl;
//    cout << "Prox de Prim: " << lista.primeiro->proximo << endl;
//    cout << "Prox Ultimo:  " << lista.ultimo->proximo << endl;
//
//    inserir(lista,8);
//    inserir(lista,72);
//    inserir(lista,9);
//    inserir(lista,14);
//    inserir(lista,5);
//    inserir(lista,23);
//
//    mostrar(lista);
//
//    cout << "E.M.Ant: " << pegaAnterior(lista,23) << endl;
//
//    retirarPorChave(lista,23);
//
//    mostrar(lista);
    TListaA lista;

    criarListaVazia(lista);
    cout << "Primeiro: " << lista.primeiro << endl;
    cout << "Último: " << lista.ultimo << endl;

    retirarPos(lista,3);
    cout << "Posição da chave: " << buscarChave(lista,15) << endl;

    inserir(lista,5);
    inserir(lista,8);
    inserir(lista,14);
    inserir(lista,7);
    inserir(lista,2);
    inserir(lista,15);
    inserir(lista,0);
    inserir(lista,6);
    inserir(lista,3);
    inserir(lista,1);
    mostrar(lista);

    retirarPos(lista,3);

    mostrar(lista);

    inserir(lista,45);
    mostrar(lista);

    inserir(lista,23);
    mostrar(lista);

    retirarPos(lista,13);

    cout << "Posição da chave: " << buscarChave(lista,51) << endl;
    cout << "aqui" << endl;
    retirarPos(lista,buscarChave(lista,15));
    mostrar(lista);

    retirarPos(lista,buscarChave(lista,51));
    mostrar(lista);

    return 0;
}
