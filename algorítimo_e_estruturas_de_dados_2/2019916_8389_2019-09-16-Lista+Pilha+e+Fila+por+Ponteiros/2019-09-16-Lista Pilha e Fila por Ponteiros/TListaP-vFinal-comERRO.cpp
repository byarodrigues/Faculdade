#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS

struct TItem{
    int chave;//obrigatório 1 campo que diferencie os elementos
    // ... demais campos que desejar.
};

struct TCelula{
    TItem item;
    TCelula *proximo;
};

struct TListaP{
    TCelula *primeiro;
    TCelula *ultimo;
    int contItens;
};


// OPERAÇÕES BÁSICAS

void criarListaPVazia(TListaP &lp){
    lp.primeiro = new TCelula;  // criei uma NOVA célula e chamei-a de PRIMEIRO
    lp.ultimo = lp.primeiro;    // atribuí o mesmo endereço de primeiro para ULTIMO
    lp.primeiro->proximo = NULL;
    lp.contItens = 0;
}

bool estaVazia(TListaP lp){
    return lp.primeiro == lp.ultimo;
}

void inserir(TListaP &lp, TItem x){
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = NULL;
    lp.contItens++;
}

void mostrar(TListaP lp){

    if (estaVazia(lp)){
        cout << "Lista vazia! Nenhum elemento para mostrar!" << endl;

    }
    else{
        TCelula *celAux;
        celAux = lp.primeiro->proximo; // começa como a primeira célula válida, ie, que tem item válido

        cout << "=== MOSTRANDO A LISTA === "<< endl;
        while (celAux != NULL){
            cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->item.chave << endl;
            celAux = celAux->proximo;
        }
    }
}

TCelula *pegaAnterior(TListaP lp, int chave){
    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;   //não começamos pela célula válida, e sim
                            // pela cabeça

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL){
        if (celAux->proximo->item.chave == chave){
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
    cout << "EM Excluído: " << q << endl;
    delete(q);
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaP lista; // instanciação

    //preparando a lista para uso!
    criarListaPVazia(lista);

    // preparo um item para colocar na lista
    TItem itemAux;
    itemAux.chave = 5;
    //itemAux.outrocampo = ???
    //...
    inserir(lista,itemAux);

    itemAux.chave = 8;
    inserir(lista,itemAux);

    itemAux.chave = 72;
    inserir(lista,itemAux);

    mostrar(lista);

    retirarPorChave(lista,23);
    // ACONTECEU UM PROBLEMA E TRAVOU O PROGRAMA! DIVIRTAM-SE!!!

    //mostrar(lista);


    return 0;
}
