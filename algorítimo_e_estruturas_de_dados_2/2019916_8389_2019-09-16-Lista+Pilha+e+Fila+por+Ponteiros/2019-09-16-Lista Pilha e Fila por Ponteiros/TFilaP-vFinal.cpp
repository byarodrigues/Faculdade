#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS
struct TItem{
    int chave;//obrigatório 1 campo que diferencie os elementos
    // ... demais campos que desejar.
};

struct TCelula{
    //int item; // era primitivo
    TItem item;
    TCelula *proximo;
};

struct TFilaP{
    TCelula *frente;
    TCelula *tras;
    int contItens;
};


// OPERAÇÕES BÁSICAS

void criarFilaPVazia(TFilaP &f){
   f.frente = new TCelula;
   f.tras = f.frente;
   f.frente->proximo = NULL;
   f.contItens = 0;
}

bool estaVaziaChique(TFilaP f){
    return f.contItens == 0;
}

bool estaVazia(TFilaP f){
    return f.frente == f.tras;
}

void enfileirar(TFilaP &f, TItem x){
    f.tras->proximo = new TCelula;
    f.tras = f.tras->proximo;
    f.tras->item = x;
    f.tras->proximo = NULL;
    f.contItens++;
}

void mostrar(TFilaP f){
    TCelula *celAux;
    celAux = f.frente->proximo;

    cout << "=== MOSTRANDO A FILA === "<< endl;
    if (estaVaziaChique(f)){
        cout << "Fila vazia! Nenhum elemento para mostrar!" << endl;
    }
    else{
        while (celAux != NULL){
            cout << "E.M.Cel: " << celAux << "   -   Chave: " << celAux->item.chave << endl;
            celAux = celAux->proximo;
        }
    }
}

void desenfileirar(TFilaP &f){
    if (estaVazia(f)){
        cout << "Fila Vazia! Nenhum elemento para desenfileirar..." << endl;
    }
    else{
        TCelula *aux = f.frente;
        cout << "Desenfilerei o item de chave: " << aux->proximo->item.chave << endl;
        f.frente = f.frente->proximo;
        delete(aux);
        f.contItens--;
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TFilaP fila; // instanciação

    //preparando a lista para uso!
    criarFilaPVazia(fila);

    mostrar(fila);

    // preparo um item para colocar na pilha
    TItem itemAux;
    itemAux.chave = 5;
    //itemAux.outrocampo = ???
    //...
    enfileirar(fila,itemAux);
    //outro item
    itemAux.chave = 8;
    enfileirar(fila,itemAux);
    itemAux.chave = 72;
    enfileirar(fila,itemAux);

    mostrar(fila);

    desenfileirar(fila);

    mostrar(fila);
    desenfileirar(fila);

    mostrar(fila);

     desenfileirar(fila);

    mostrar(fila);
     desenfileirar(fila);

    mostrar(fila);


    return 0;
}
