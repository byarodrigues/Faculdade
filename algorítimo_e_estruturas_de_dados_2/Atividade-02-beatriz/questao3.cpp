#include <iostream>
#include <clocale>
using namespace std;

const int maxTam=50;
struct Tproduto{
    string codigo;
    string nome;
    string preco;
    int quantidade;
};
struct Tlista{
    Tproduto Vetproduto[maxTam];
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
        cout << "codigo:" << endl;
        cin >> l.Vetproduto[l.ultimo].codigo;
        cout << "nome:" << endl;
        cin >> l.Vetproduto[l.ultimo].nome;
        cout << "preco:" << endl;
        cin >> l.Vetproduto[l.ultimo].preco;
        cout << "quantidade em estoque:" << endl;
        cin >> l.Vetproduto[l.ultimo].quantidade;
        l.ultimo ++;
}
void MostrarEstoqB(Tlista l){
    if (estaVazia(l)){
        cout << "Nada para mostrar. Lista vazia!" << endl;
    }
    else{
        for (int i=0;i<l.ultimo;i++){
            if (l.Vetproduto[i].quantidade < 5){
                cout << "produto " << l.Vetproduto[i].nome << " com o estoque baixo" << endl;
            }
            else {
                if (i=l.ultimo - 1){
                    cout << "sem produtos acabando" << endl;
                }
            }
        }
    }
}
int buscarItem(Tlista l, string c){
    bool achou = false;
    int pegaitem;
    if (estaVazia(l)){
        return -1;
    }
    else{
        for(int i=l.primeiro;i<l.ultimo;i++){
            if(l.Vetproduto[i] == c){
                achou = true;
                pegaitem = i;
                break;
            }
        }
        if(achou == true){
            return pegaitem;
        }
        else{
            return -1;
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

int main(){
    setlocale(LC_ALL,"Portuguese");
    TLista l;
    criarListaVazia(l);
    char resp:

    for(int i=0;i< maxTam; i++){
        cout << "deseja inserir um cliente?(S-para sim e N- para nao)" << endl;
        cin >> resp >> endl;
        if (resp == s){
            inserir(l);
        }
        else {
                return 0;
        }
    }
    mostrarEstoqB(l);
    buscariItem(l);

return 0;
}
