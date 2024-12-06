#include <iostream>
#include <clocale>
using namespace std;

// SESSÃO DE DECLARAÇÕES

const int maxTam = 10;

// ESTRUTURA
struct TLista_A{
    int vetItens[maxTam]; //suporte para os itens
    int primeiro;   // controle
    int ultimo;     // controle
};

// OPERAÇÕES BÁSICAS
void criarListaVazia(TLista_A &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}

bool estaVazia(TLista_A l){
    return l.primeiro == l.ultimo;
//    if(l.primeiro == l.ultimo){
//        return true;
//    }
//    else{
//        return false;
//    }
}

bool estaCheia(TLista_A l){
    return l.ultimo >= maxTam;
}
             //onde      //o que?
void inserir(TLista_A &l, int x){
    if(estaCheia(l)){ // testa pra ver se cabe
        cout << "A lista está cheia. Não posso inserir." << endl;
    }
    else{
        l.vetItens[l.ultimo] = x;   //orienta ou controla a posição em que
        l.ultimo++;                 // o item será alocado
    }
}

void mostrar(TLista_A l){

    cout << "=== MOSTRANDO ITENS DA LISTA===" << endl;
    for(int i=l.primeiro;i<l.ultimo;i++){
        cout << "Pos " << i << ": " << l.vetItens[i] << endl;
    }
}

void retirarPos(TLista_A &l, int p){
    int aux;

    if((estaVazia(l)) || (p>=l.ultimo) || (p<l.primeiro)){
        cout << "Não posso retirar! Lista vazia ou posição fora do limite" << endl;
    }
    else{
       l.ultimo--;
       for(aux=p;aux<l.ultimo;aux++){
            l.vetItens[aux] = l.vetItens[aux+1];
       }
    }
}

int buscarChave(TLista_A l, int c){
    bool achou = false;
    int pegaPos;

    if (estaVazia(l)){
        return -1;
    }
    else{
        for(int i=l.primeiro;i<l.ultimo;i++){
            if(l.vetItens[i]== c){
                achou = true;
                pegaPos = i;
                break;
            }
        }
        if(achou == true){
            return pegaPos;
        }
        else{
            return -1;
        }
    }
}

void retirarChave(TLista_A &l,int c){
    // big procedimento que localiza e retira
    // ou vou apenas localizar e pegar a posição,
    // chamando o retirarPos em seguida???

    // DESAFIO: junte a FUNÇÃO buscarChave com o PROCED retirarPos
    // e construa este retirarChave
}

int main(){

    setlocale(LC_ALL,"Portuguese");//para acentuação e caracteres especiais

    TLista_A lista; //instanciação

    criarListaVazia(lista); // prepara para o uso
    cout << "Primeiro: " << lista.primeiro << endl;
    cout << "Último: " << lista.ultimo << endl;

    retirarPos(lista,3);
    cout << "Posição da chave: " << buscarChave(lista,15) << endl;

    inserir(lista,5); // coloca um item
    inserir(lista,8);
    inserir(lista,14);
    inserir(lista,7);
    inserir(lista,2);
    inserir(lista,15);
    inserir(lista,0);
    inserir(lista,6);
    inserir(lista,3);
    inserir(lista,1);
    mostrar(lista);

    retirarPos(lista,3);

    mostrar(lista);

    inserir(lista,45);
    mostrar(lista);

    inserir(lista,23);
    mostrar(lista);

    retirarPos(lista,13);

    cout << "Posição da chave: " << buscarChave(lista,51) << endl;
    cout << "aqui" << endl;
    retirarPos(lista,buscarChave(lista,15));
    mostrar(lista);

    retirarPos(lista,buscarChave(lista,51));
    mostrar(lista);

    return 0;
}
