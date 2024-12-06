#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS

struct TItem{
    int chave;
    string nome;
    //...
};

struct TNo{
    TItem item;
    TNo *esquerda;
    TNo *direita;
};

struct TArvoreBin{ // frescura!!! Brincadeiras à parte, essa struct não é essencial. Eu a uso para colocar campos complementares.
    string nomeArvore;
    int contItens;
    TNo *raiz;
};

// OPERAÇÕES
void criarArvoreBinVazia(TArvoreBin &a, string n){
    a.nomeArvore = n;
    a.contItens = 0;
    a.raiz = NULL;
}

void inserir(TArvoreBin &a, TNo *&no, TItem i){
    if (no == NULL){ // CASO BASE/PARADA
        no = new TNo;
        no->item = i;
        no->esquerda = NULL;
        no->direita = NULL;
        a.contItens++;
        if (a.raiz == NULL){
            a.raiz = no;
        }
    }
    else{
        if (i.chave < no->item.chave){ // chamada recursiva ESQ
            inserir(a,no->esquerda,i);
        }
        else{
            if (i.chave > no->item.chave){ // chamada recursiva DIR
                inserir(a,no->direita,i);
            }
            else{
                if (i.chave == no->item.chave){
                    cout << "Não posso inserir. Item já existe!" << endl;
                 }
            }
        }

    }
}

void percorrerINOrdem(TNo *&no){
    if(no!=NULL){
        percorrerINOrdem(no->esquerda);
        cout << no->item.chave << ", "; // operação a ser realizada! É o que conseguimos perceber na saída.
        percorrerINOrdem(no->direita);
    }
}

void percorrerPreOrdem(TNo *&no){
    if(no!=NULL){
        cout << no->item.chave << ", ";
        percorrerPreOrdem(no->esquerda);
        percorrerPreOrdem(no->direita);
    }
}

void percorrerPosOrdem(TNo *&no){
    if(no!=NULL){
        percorrerPosOrdem(no->esquerda);
        percorrerPosOrdem(no->direita);
        cout << no->item.chave << ", ";
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");

    TArvoreBin arvore1;
    criarArvoreBinVazia(arvore1,"Teste");

    TItem iAux;
    iAux.chave = 8;
    iAux.nome = "Gab";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 5;
    iAux.nome = "Lala";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 9;
    iAux.nome = "Doido";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 5;
    iAux.nome = "Lala";
    inserir(arvore1,arvore1.raiz,iAux);

    cout << "IN ORDEM: " << endl;
    percorrerINOrdem(arvore1.raiz);
    cout << endl;
    cout << "PRE ORDEM: " << endl;
    percorrerPreOrdem(arvore1.raiz);
    cout << endl;
    cout << "POS ORDEM: " << endl;
    percorrerPosOrdem(arvore1.raiz);
    cout << endl;

    return 0;
}
