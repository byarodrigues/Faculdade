#include <iostream>
#include <clocale>
using namespace std;

// PARA CASA:   crie a estrutura e as operações necessárias para manipular
//              uma lista de produtos. Cada produto tem código, nome e preço.
//              Demonstrem a sua utilização!

// SESSÃO DE DECLARAÇÕES

const int maxTam = 10;

// ESTRUTURA
struct Tlista{
    int codigo;
    string nome;
    int preco;
    int primeiro;
    int ultimo;
};
criarListaVazia(Tlista &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}
estaCheia(Tlista l){
    return l.ultimo >= maxTam;
}
estaVazia(Tlista l){
    return l.primeiro == l.ultimo;
}
inserir(Tlista &l, int x){
    if (estaCheia(l)){
        cout << "lista cheia, nao pode inserir" << endl;
    }
    else{

        l.ultimo++;
    }
}
retirarChave(){
}
mostrar(){
}


int main(){

    setlocale(LC_ALL,"Portuguese");//para acentuação e caracteres especiais

    TLista_A lista; //instanciação

    criarListaVazia(lista); // prepara para o uso


    return 0;
}
