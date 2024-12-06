/*    Exerc�cio 2.
    - Salve este arquivo como TListaDP-v3.cpp;
    - modifique este TAD de modo que N�O exista nenhuma c�lula
      sem item v�lido.
*/
#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS
struct TItem{
    int chave;
    // ...
};

struct TCelula{
    TCelula *anterior;
    TItem item;
    TCelula *proximo;
};

struct TListaDP{
    TCelula *primeiro;
    TCelula *ultimo;
};


// OPERA��ES B�SICAS

void criarListaPVazia(TListaDP &lp){
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->anterior = NULL; //adicionado para duplamente encadeada
    lp.primeiro->proximo = NULL;
}

void inserir(TListaDP &lp, TItem x){
    lp.ultimo->proximo = new TCelula;
    lp.ultimo->proximo->anterior = lp.ultimo;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = NULL;
    // "debugando" na unha
    cout << "-------------------------------" << endl;
    cout << "Novo Ultimo:  " << lp.ultimo << endl;
    cout << "Ant de Ult:   " << lp.ultimo->anterior << endl;
    cout << "Prox Ultimo:  " << lp.ultimo->proximo << endl;
}
//
void mostrarED(TListaDP lp){
    TCelula *celAux;
    celAux = lp.primeiro->proximo; // come�a como a primeira c�lula v�lida, ie, que tem item v�lido

    cout << "=== MOSTRANDO A LISTA DA ESQ->DIR === "<< endl;
    while (celAux != NULL){
        cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->item.chave << endl;
        celAux = celAux->proximo;
    }
}

void mostrarDE(TListaDP lp){
    TCelula *celAux;
    celAux = lp.ultimo; // come�a pela c�lula ULTIMO, pois j� tem item v�lido

    cout << "=== MOSTRANDO A LISTA DA DIR->ESQ === "<< endl;
    while (celAux != lp.primeiro){
        cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->item.chave << endl;
        celAux = celAux->anterior;
    }
}
//
//TCelula *pegaAnterior(TListaP lp, int chave){
//    TCelula *celAux;
//    bool achou = false;
//
//    celAux = lp.primeiro;   //n�o come�amos pela c�lula v�lida, e sim
//                            // pela cabe�a
//
//    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
//    while (celAux->proximo != NULL){
//        if (celAux->proximo->item == chave){
//            achou = true;
//            return celAux;
//        }
//        celAux = celAux->proximo;
//    }
//    if (achou == false){
//        return NULL;
//    }
//}
//
//void retirarPorChave(TListaP &lp, int chave){
//    TCelula *p = pegaAnterior(lp,chave); //anterior
//    TCelula *q; //alvo
//
//    q = p->proximo;
//    p->proximo = q->proximo;
//    cout << "EM Exclu�do: " << q << endl;
//    delete(q);
//}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaDP lista; // instancia��o

    //preparando a lista para uso!
    criarListaPVazia(lista);

    cout << "EM cel Prim:  " << lista.primeiro << endl;
    cout << "EM cel Ulti:  " << lista.ultimo << endl;
    cout << "Ant de Prim:  " << lista.primeiro->anterior << endl;
    cout << "Prox de Prim: " << lista.primeiro->proximo << endl;
    cout << "Ant de Ult:   " << lista.ultimo->anterior << endl;
    cout << "Prox Ultimo:  " << lista.ultimo->proximo << endl;

    TItem iAux;
    iAux.chave = 5;
    inserir(lista,iAux);

    iAux.chave = 7;
    inserir(lista,iAux);

    iAux.chave = 4;
    inserir(lista,iAux);

    mostrarED(lista);
    mostrarDE(lista);

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
    return 0;
}
