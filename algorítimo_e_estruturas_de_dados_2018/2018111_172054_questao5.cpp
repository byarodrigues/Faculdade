#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

//DECLARAÇÕES


const int maxTam = 10;

struct TConta{
    int numero;
    string tipo;
    double saldo;
};

struct TCliente{
    string nome;
    int cpf;
    int idade;
    TConta conta;
};

struct TCelula{
    TCliente item;
    TCelula *proximo;
};

// TAD LISTA POR PONTEIRO
struct TListaP{
    TCelula *primeiro, *ultimo;
};


// OPERAÇÕES
void criarListaP(TListaP &l){
    l.primeiro = new TCelula;
    l.ultimo = l.primeiro;
    l.ultimo->proximo = NULL;
}

bool estaVaziaLP(TListaP l){
    return l.primeiro->proximo == NULL;
}

void inserir(TCliente c, TListaP &l){
    l.ultimo->proximo = new TCelula;
    l.ultimo = l.ultimo->proximo;
    l.ultimo->item = c;
    l.ultimo->proximo = NULL;
}

void mostrarLP(TListaP l){

    cout << "--------- MOSTRAR LISTA ----------" << endl;
    if (estaVaziaLP(l)){
        cout << "Lista Vazia. Nada para mostrar!" << endl;
    }
    else{
        TCelula *celAux = l.primeiro->proximo;

        while (celAux != NULL) {
            cout << "Nome: " << celAux->item.nome << endl;
            celAux = celAux->proximo;
        }
    }
}

// TAD FILA POR PONTEIRO
    struct TFilaP{
        TCelula *frente, *tras;
    };

// OPERAÇÕES BÁSICAS DA FILA
void criarFilaP(TFilaP &f){
    f.frente = new TCelula;
    f.tras = f.frente;
    f.tras->proximo = NULL;
}

bool estaVaziaFP(TFilaP f){
    return f.frente == f.tras;
}

void enfileirar(TCliente c, TFilaP &f){
    f.tras->proximo = new TCelula;
    f.tras = f.tras->proximo;
    f.tras->item = c;
    f.tras->proximo = NULL;
}

void mostrarFP(TFilaP f){

    cout << "--------- MOSTRAR FILA ----------" << endl;
    if (estaVaziaFP(f)){
        cout << "Fila Vazia. Nada para mostrar!" << endl;
    }
    else{
        TCelula *celAux = f.frente->proximo;

        while (celAux != NULL) {
            cout << "Nome: " << celAux->item.nome << endl;
            celAux = celAux->proximo;
        }
    }
}

// TAD PILHA POR PONTEIRO
    struct TPilhaP{
        TCelula *fundo, *topo;
    };

// OPERAÇÕES BÁSICAS DA PILHA
void criarPilhaP(TPilhaP &p){
    p.fundo = new TCelula;
    p.topo = p.fundo;
    p.fundo->proximo = NULL;
}

bool estaVaziaPP(TPilhaP p){
    return p.topo->proximo == NULL;
}

void empilhar(TCliente c,TPilhaP &p){
    TCelula *celAux = new TCelula;
    p.topo->item = c;
    celAux->proximo = p.topo;
    p.topo = celAux;
}

void mostrarPP(TPilhaP p){

    cout << "--------- MOSTRAR PILHA ----------" << endl;
    if (estaVaziaPP(p)){
        cout << "Pilha Vazia. Nada para mostrar!" << endl;
    }
    else{
        TCelula *celAux = p.topo->proximo;

        while (celAux != NULL) {
            cout << "Nome: " << celAux->item.nome << endl;
            celAux = celAux->proximo;
        }
    }
}

/// ============================================

// OPERAÇÕES ESPECÍFICAS DO PROBLEMA

void cadClientes(TListaP &l,int maxClientes){
    int contClientes = 1;
    string resp = "S";
    TCliente auxCli;

    while ((contClientes <= maxClientes) && (resp != "N")){
        cout << "Cliente " << contClientes << ": " << endl;
        cout << "   Nome:  ";
        cin >> auxCli.nome;
        cout << "   Conta:  " << endl;
        cout << "     Número:  ";
        cin >> auxCli.conta.numero;
        cout << "     Saldo:  ";
        cin >> auxCli.conta.saldo;
        inserir(auxCli,l);
        contClientes++;
        cout << "Deseja cadastrar outro cliente? (S/N) :   ";
        cin >> resp;
    }
}

double saldoTotal(TListaP l){
    double somaSaldo = 0;

cout << "--------- SALDO TOTAL ----------" << endl;
    if (estaVaziaLP(l)){
        cout << "Lista Vazia. Nada de saldo!" << endl;
    }
    else{
        TCelula *celAux = l.primeiro->proximo;

        while (celAux != NULL) {
            somaSaldo = somaSaldo + celAux->item.conta.saldo;
            celAux = celAux->proximo;
        }
    }

    return somaSaldo;
}

void colocarNaFila(TListaP l, TFilaP &f){
    string resp = "S";

    TCelula *celAux = l.primeiro->proximo;

        while ((celAux != NULL) && (resp == "S")) {
            enfileirar(celAux->item,f);
            celAux = celAux->proximo;
            cout << "Colocar outro cliente na fila? (S/N):  ";
            cin >> resp;
        }
}

void atender(TFilaP &f, TPilhaP &p){
    string resp = "S";

    TCelula *celAux = f.frente->proximo;

        while (celAux != NULL) {
            empilhar(celAux->item,p);
            celAux = celAux->proximo;
        }
}
int main(){

    TListaP listaClientes;
    criarListaP(listaClientes);
    int maxCli;

    cout << "Máximo de clientes:  ";
    cin >> maxCli;
    cadClientes(listaClientes,maxCli);
    mostrarLP(listaClientes);
    cout << "Saldo Total: " << saldoTotal(listaClientes) << endl;

    TFilaP filaAtend;
    criarFilaP(filaAtend);
    colocarNaFila(listaClientes,filaAtend);
    mostrarFP(filaAtend);
    mostrarLP(listaClientes);

    TPilhaP pilhaAtend;
    criarPilhaP(pilhaAtend);
    atender(filaAtend,pilhaAtend);
    mostrarFP(filaAtend);
    mostrarPP(pilhaAtend);
    mostrarLP(listaClientes);

    return 0;
}
