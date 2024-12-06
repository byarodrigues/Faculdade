/*
    INSTITUTO FEDERAL MINAS GERAIS � campus Bambu�
    Departamento de Engenharias e Computa��o � DEC / N�cleo de Computa��o � NC
    Disciplina: Algoritmos e Estruturas de Dados 2 - AED2
    Per�odo: 2019/2 - Prof. Me. Gabriel da Silva

    Arquivo base para quest�o 3 da Prova 1
*/

#include <iostream>
#include <clocale>
using namespace std;

//DECLARA��ES
const int maxTam = 10;

// tipos TConta e TCliente
// ...



// TAD LISTA POR ARRANJO
struct TListaA{
    TCliente vetClientes[maxTam];
    int primeiro,ultimo;
};


// OPERA��ES DA LISTA
void criarListaA(TListaA &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}

bool estaCheiaLA(TListaA l){
    // ...
}

bool estaVaziaLA(TListaA l){
    return l.primeiro == l.ultimo;
}
                               // agora, o tipo � TAluno
void inserir(TListaA &l, TCliente cliente){
    if (estaCheiaLA(l)){
        cout << "N�o cabe mais nada fiote!" << endl;
    }
    else{
       // ...
    }
}

void mostrarLA(TListaA l){

    cout << "---------- Mostrando a Lista de Clientes ----------" << endl;
    if (estaVaziaLA(l)){
        cout << "  N�o h� clientes cadastrados!" << endl;
    }
    else{
        for (int cont=l.primeiro;cont<l.ultimo;cont++){
            cout << "  Cliente " << cont+1 << ":" << endl;
            cout << "    Nome: " << l.vetClientes[cont].nome << endl;
            // mostre os demais dados
            cout << "  ------------------------- " << endl;
        }
    }
}

// TAD FILA POR PONTEIRO

    struct TCelula{
        TCliente item;
        TCelula *proximo;
    };

    struct TFilaP{
        TCelula *frente, *tras;
    };

// OPERA��ES B�SICAS DA FILA
void criarFilaP(TFilaP &f){
    f.frente = new TCelula;
    f.tras = f.frente;
    f.tras->proximo = NULL;
}

bool estaVaziaFP(TFilaP f){
    return f.frente == f.tras;
}

void enfileirar(TCliente c, TFilaP &f){
    // ...
}

void desenfileirar(TFilaP &f){

    TCelula *pCelAux;

    if ((estaVaziaFP(f)))
    {
        cout << "Fila vazia! Nenhum cliente para atender." << endl;
        return;
    }
    else
    {
       // ...
    }
}


void mostrarFP(TFilaP f){

    cout << "--------- Mostrando a Fila de Clientes ----------" << endl;
    if (estaVaziaFP(f)){
        cout << "Fila Vazia. Nada para mostrar!" << endl;
    }
    else{
        // ...
    }
}

/// ============================================

// OPERA��ES ESPEC�FICAS DO PROBLEMA

void cadClientes(TListaA &l){
    int contClientes = 1;
    string resp = "S";
    TCliente auxCli;

    cout << "---------- Cadastrando os Clientes na Lista ----------" << endl;

    while ((contClientes <= maxTam) && (resp != "N") && (resp != "n")){
        // coletando os dados do cliente
        cout << "Cliente " << contClientes << ": " << endl;
        cout << "   Nome:  ";
        cin >> auxCli.nome;
        cout << "   Conta:  " << endl;
        cout << "     N�mero:  ";
        cin >> auxCli.conta.numero;
        cout << "     Saldo:  ";
        cin >> auxCli.conta.saldo;
        // colocar na lista
        // ...
        contClientes++;
        cout << "Deseja cadastrar outro cliente? (S/N) :   ";
        cin >> resp;
    }
}

double saldoTotal(TListaA l){
    double somaSaldo = 0;

    // ...
    return somaSaldo;
}


void colocarNaFila(TListaA l, TFilaP &f){
    int numConta;
    bool achou = false;
    string resp = "S";
    int contClientes = 1;

    cout << "--------- Colocando clientes na Fila ----------" << endl;

    // Esta procedimento n�o faz o tratamento para verificar se um cliente j� est�
    // na fila. Pode ignorar isso na prova! N�O PRECISA FAZER ESTA CHECAGEM!

    while ((contClientes <= l.ultimo) && (resp != "N") && (resp != "n")){
        cout << "Informe o n�mero da conta: ";
        cin >> numConta;

        // ...
    }
}

void atender(TFilaP &f){
    cout << "\n--------- Atendendo Clientes da Fila ---------" << endl;
    TCelula *celAux = f.frente->proximo;

    while (celAux != NULL) {
        // ...
    }
}
int main(){

    setlocale(LC_ALL,"Portuguese");

    cout << "\n--------- BANCO ENGCOMP ---------" << endl;

    //  criar a lista e colocar os clientes
    // ...

    // mostrar o saldo
    cout << "Saldo Total: " << saldoTotal(listaClientes) << endl;

    // criar a fila e colocar clientes nela
    TFilaP filaClientes;
    criarFilaP(filaClientes);
    // ...

    // atender os clientes
    atender(filaClientes);

    // mostrar as 2 estruturas
    mostrarFP(filaClientes);
    mostrarLA(listaClientes);

    return 0;
}
