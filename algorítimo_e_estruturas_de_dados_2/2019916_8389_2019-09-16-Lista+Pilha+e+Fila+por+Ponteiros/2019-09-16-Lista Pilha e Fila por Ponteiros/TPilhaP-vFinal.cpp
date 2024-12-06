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

struct TPilhaP{
    TCelula *topo;
    TCelula *fundo;
    int contItens;
};


// OPERAÇÕES BÁSICAS

void criarPilhaPVazia(TPilhaP &p){
   p.topo = new TCelula;
   p.fundo = p.topo;
   p.fundo->proximo = NULL;
   p.contItens = 0;
}

bool estaVazia(TPilhaP p){
    return p.topo == p.fundo;
}

void empilhar(TPilhaP &p, TItem x){
    TCelula *aux = new TCelula;
    p.topo->item = x; // aquela célula que não tinha item
    aux->proximo = p.topo;
    p.topo = aux;
    p.contItens++;
}


void mostrar(TPilhaP p){
    TCelula *celAux;
    celAux = p.topo->proximo;

    cout << "=== MOSTRANDO A PILHA === "<< endl;
    if (estaVazia(p)){
        cout << "Pilha vazia! Nenhum elemento para mostrar!" << endl;
    }
    else{
        while (celAux != NULL){
            cout << "E.M.Cel: " << celAux << "   -   Chave: " << celAux->item.chave << endl;
            celAux = celAux->proximo;
        }
    }
}

void desempilhar(TPilhaP &p){
    if (estaVazia(p)){
        cout << "Nenhum elemento para desempilhar. Pilha Vazia!" << endl;
    }
    else{
        TCelula *aux = p.topo;
        cout << "Chave do elemento desempilhado: " << aux->proximo->item.chave << endl;
        p.topo = p.topo->proximo;
        delete(aux);
        p.contItens--;
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TPilhaP pilha; // instanciação

    //preparando a lista para uso!
    criarPilhaPVazia(pilha);

    mostrar(pilha);

    // preparo um item para colocar na pilha
    TItem itemAux;
    itemAux.chave = 5;
    //itemAux.outrocampo = ???
    //...
    empilhar(pilha,itemAux);
    //outro item
    itemAux.chave = 8;
    empilhar(pilha,itemAux);
    itemAux.chave = 72;
    empilhar(pilha,itemAux);

    mostrar(pilha);

    desempilhar(pilha);
    desempilhar(pilha);

    desempilhar(pilha);
    //desempilhar(pilha);


    mostrar(pilha);

    return 0;
}
