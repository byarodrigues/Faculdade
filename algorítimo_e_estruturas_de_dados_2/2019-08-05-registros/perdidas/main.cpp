#include <iostream>
#include "bibTadLinear.h"

using namespace std;

int main()
{

    TListaA lista;
    criarListaVazia(lista);

//    if (estaCheia(lista)){
//        cout << "Está Cheia" << endl;
//    }
//    else{
//        cout << "Não está Cheia" << endl;
//    }

    TItem iAux;

    iAux.valor = 5;
    inserir(iAux,lista);
    cout << contaItens(lista) << endl;

    iAux.valor = 3;
    inserir(iAux,lista);
    cout << contaItens(lista) << endl;

    iAux.valor = 1;
    inserir(iAux,lista);
    cout << contaItens(lista) << endl;

    iAux.valor = 4;
    inserir(iAux,lista);
    cout << contaItens(lista) << endl;

    mostrarItens(lista);

    return 0;
}
