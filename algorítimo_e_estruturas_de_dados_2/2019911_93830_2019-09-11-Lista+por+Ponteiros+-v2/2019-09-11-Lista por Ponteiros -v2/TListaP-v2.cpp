#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS
struct TCelula{
    int item;
    TCelula *proximo;
};

struct TListaP{
    TCelula *primeiro;
    TCelula *ultimo;
};


// OPERA��ES B�SICAS

void criarListaPVazia(TListaP &lp){
    lp.primeiro = new TCelula;  // criei uma NOVA c�lula e chamei-a de PRIMEIRO
    lp.ultimo = lp.primeiro;    // atribu� o mesmo endere�o de primeiro para ULTIMO
    lp.primeiro->proximo = NULL;
}

void inserir(TListaP &lp, int x){
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = NULL;
}

void mostrar(TListaP lp){
    TCelula *celAux;
    //celAux = lp.primeiro; // come�a como ponto de acesso, logo, n�o tem item v�lido
    celAux = lp.primeiro->proximo; // come�a como a primeira c�lula v�lida, ie, que tem item v�lido

    cout << "=== MOSTRANDO A LISTA === "<< endl;
    while (celAux != NULL){
        cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->item << endl;
        celAux = celAux->proximo;
    }
}

TCelula *pegaAnterior(TListaP lp, int chave){
    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;   //n�o come�amos pela c�lula v�lida, e sim
                            // pela cabe�a

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL){
        if (celAux->proximo->item == chave){
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
        return NULL;
    }
}

void retirarPorChave(TListaP &lp, int chave){
    TCelula *p = pegaAnterior(lp,chave); //anterior
    TCelula *q; //alvo

    q = p->proximo;
    p->proximo = q->proximo;
    cout << "EM Exclu�do: " << q << endl;
    delete(q);
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaP lista; // instancia��o

    //preparando a lista para uso!
    criarListaPVazia(lista);

    cout << "EM cel Prim: " << lista.primeiro << endl;
    cout << "EM cel Ulti: " << lista.ultimo << endl;
    cout << "Prox de Prim: " << lista.primeiro->proximo << endl;
    cout << "Prox Ultimo:  " << lista.ultimo->proximo << endl;

    inserir(lista,8);
    inserir(lista,72);
    inserir(lista,9);
    inserir(lista,14);
    inserir(lista,5);
    inserir(lista,23);

    mostrar(lista);

    cout << "E.M.Ant: " << pegaAnterior(lista,23) << endl;

    retirarPorChave(lista,23);

    mostrar(lista);
    return 0;
}
