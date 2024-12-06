#include <iostream>
#include <clocale>
using namespace std;

int const maxTam=100;

struct TProduto{
    int codigo;
    string nome;
    double preco;
};

struct TLista_A{
    int primeiro, ultimo;
    TProduto produto[maxTam];
};

void criarListaVazia(TLista_A &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}

bool estaVazia(TLista_A l){
    return l.primeiro == l.ultimo;
}

bool estaCheia(TLista_A l){
    return l.ultimo >= maxTam;
}

void inserir(TLista_A &l, TProduto x){
    if(estaCheia(l)){
        cout << "A lista está cheia. Não posso inserir." << endl;
    }
    else{
        l.produto[l.ultimo] = x;
        l.ultimo++;
    }
}

void mostrar(TLista_A l){
    cout << "=== MOSTRANDO ITENS DA LISTA===" << endl;
    for(int i=l.primeiro;i<l.ultimo;i++){
        cout << "Codigo: " << l.produto[i].codigo << endl;
        cout << "Nome: " << l.produto[i].nome << endl;
        cout << "Preço: " << l.produto[i].preco <<endl;
    }
}

void cadastrar(TLista_A &l){
    TProduto produto;
    char cad = 'S';
    int qtd=0;
    while(cad == 'S' || cad == 's' || qtd <=100){
        cout << "Informe o nome do Produto: ";
        cin >>produto.nome;
        cout << "Informe o preco do Produto: ";
        cin >> produto.preco;
        cout << "Informe o codigo do Produto: ";
        cin >> produto.codigo;
        cout << "Deseja cadastrar outro produto? ";
        cin >> cad;
        qtd++;
        inserir(l,produto);
    }
}

void selectionSort(TLista_A &l){
    if(estaVazia(l)){
        cout << "Lista Vázia!" << endl;
    }
    else{
        int i,j,Min;
        for(i=l.primeiro;i<l.ultimo-1;i++){
            Min = i;
            TProduto x;
            for(j=i+1;j<l.ultimo;j++){
                if(l.produto[j].codigo < l.produto[Min].codigo){
                    cout << "j:" << l.produto[j].codigo << "Min:" << l.produto[Min].codigo << endl;
                    Min = j;
                }
            }
            x = l.produto[Min];
            l.produto[Min] = l.produto[i];
            l.produto[i] = x;
        }
    }
}




int main(){
    setlocale(LC_ALL, "Portuguese");
    TLista_A lista;

    criarListaVazia(lista);
    cadastrar(lista);
    mostrar(lista);
    selectionSort(lista);
    mostrar(lista);
    return 0;
}
