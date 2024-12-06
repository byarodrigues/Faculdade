#include <iostream>
#include <clocale>
using namespace std;

const int maxTam=100;
struct Tconta{
    int numero;
    string tipo;
    string saldo;
};
struct Tcliente{
    int cpf;
    string nome;
    int idade;
    Tconta conta;
};
struct Tlista{
    Tcliente Vetcliente[maxTam];
    int primeiro;
    int ultimo;
};
void criarListaVazia(Tlista &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}
bool estaCheia(Tlista l){
    return l.ultimo >= maxTam;
}
bool estaVazia(Tlista l){
    return l.primeiro == l.ultimo;
}
void inserir(Tlista &l){
    if(estaCheia(l)){
        cout << "lista cheia, nao pode inserir" << endl;
    }
    else
        cout << "insira os dados do cliente:" << endl;
        cout << "cpf:" << endl;
        cin >> l.Vetcliente[l.ultimo].cpf ;
        cout << "nome:" << endl;
        cin >> l.Vetcliente[l.ultimo].nome;
        cout << "idade:" << endl;
        cin >> l.Vetcliente[l.ultimo].idade;
        cout << "numero:" << endl;
        cin >> l.Vetcliente[l.ultimo].conta.numero;
        cout << "Tipo(conta corrente ou poupanca):" << endl;
        cin >> l.Vetcliente[l.ultimo].conta.tipo;
        cout << "saldo:" << endl;
        cin >> l.Vetcliente[l.ultimo].conta.saldo;
        l.ultimo ++;
}
void mostrar(Tlista l){
    if (estaVazia(l)){
    cout << "Nada para mostrar. Lista vazia!" << endl;
    }
    else{
        cout << "=== MOSTRANDO ITENS DA LISTA===" << endl;
        for (int i=l.primeiro;i<l.ultimo;i++){
        cout << "Cliente " << i+1<< ": " << endl;
        cout << "  Cpf:" << l.Vetcliente[i].cpf << endl;
        cout << "  Nome:" << l.Vetcliente[i].nome << endl;
        cout << "  Idade:" << l.Vetcliente[i].idade << endl;
        cout << "  Dados da conta:" << endl;
        cout << "  Numero:" << l.Vetcliente[i].conta.numero << endl;
        cout << "  Tipo(conta corrente ou poupanca):" << l.Vetcliente[i].conta.tipo << endl;
        cout << "  saldo:" << l.Vetcliente[i].conta.saldo << endl;
        }
    }
}
int main(){
    setlocale(LC_ALL,"Portuguese");

    Tlista lista;

    criarListaVazia(lista);

    string resp;
    for(int i=0;i< maxTam; i++){
        cout << "deseja inserir um cliente?(S-para sim e N- para nao)" << endl;
        cin >> resp;
        if (resp == "s"){
            inserir(lista);
        }
        else {
            return -1;
        }
    }
    mostrar(lista);
    return 0;
}
