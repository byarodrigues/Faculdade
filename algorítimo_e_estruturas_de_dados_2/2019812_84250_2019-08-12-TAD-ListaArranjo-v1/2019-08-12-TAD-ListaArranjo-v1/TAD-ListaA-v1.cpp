#include <iostream>
#include <clocale>
using namespace std;

// SESS�O DE DECLARA��ES

// ESTRUTURA
struct TLista_A{
    int vetItens[10];
    int primeiro;
    int ultimo;
};

// OPERA��ES B�SICAS
void criarListaVazia(TLista_A &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}
             //onde      //o que?
void inserir(TLista_A &l, int x){
    if(l.ultimo >= 10){ // testa pra ver se cabe
        cout << "A lista est� cheia. N�o posso inserir." << endl;
    }
    else{
        l.vetItens[l.ultimo] = x;   //orienta ou controla a posi��o em que
        l.ultimo++;                 // o item ser� alocado
    }
}

bool estaVazia(TLista_A l){
    if(l.primeiro == l.ultimo){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    setlocale(LC_ALL,"Portuguese");//para acentua��o e caracteres especiais

    TLista_A lista; //instancia��o

    criarListaVazia(lista); // prepara para o uso
    cout << "Primeiro: " << lista.primeiro << endl;
    cout << "�ltimo: " << lista.ultimo << endl;

    inserir(lista,14); // coloca um item
    inserir(lista,8);

    if(estaVazia(lista)){ //verifica se est� vazia
        cout << "A lista n�o possui elementos" << endl;
    }
    else{
        cout << "A lista possui elemento(s)" << endl;
    }

    cout << "Primeiro: " << lista.primeiro << endl;
    cout << "�ltimo: " << lista.ultimo << endl;

    inserir(lista,9);
    inserir(lista,5);
    inserir(lista,14);
    inserir(lista,8);
    inserir(lista,14);
    inserir(lista,8);
    inserir(lista,14);
    inserir(lista,8);

    if(estaVazia(lista)){
        cout << "A lista n�o possui elementos" << endl;
    }
    else{
        cout << "A lista possui elemento(s)" << endl;
    }

    cout << "Primeiro: " << lista.primeiro << endl;
    cout << "�ltimo: " << lista.ultimo << endl;

    inserir(lista,16);

    return 0;
}
