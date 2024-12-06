#include <iostream>
#include <clocale>
using namespace std;

//Para demonstrar o funcionamento do seu programa:
//• utilize o conjunto de itens {5, 4, 7, 2, 9}, informado nesta ordem;
//• use os nomes: lista1A, lista2A, lista3A e lista4A para as
//instâncias definidas;
const int maxTam = 5;

struct item{
    int numero;
};
struct TListaA{
    item vetitem[maxTam];
    int primeiro;
    int ultimo;
};
void criarListaA(TListaA &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}
bool estavazia1 (TListaA l){
    return l.primeiro == l.ultimo;
}
bool estaCheia1(TListaA l){
    return l.ultimo >= maxTam;
}

//inserir os elementos em ordem crescente na lista
void inserirCrescente(item it,TListaA &l){
    if (estaCheia1(l)){
        cout << "lista cheia, nao pode inserir" << endl;
    }
    else {
       if (estavazia1(l)){
            l.vetitem[l.ultimo] = it;
            l.ultimo ++;
        }
        else {
            int pos = l.ultimo;
            for (int i=l.primeiro;i<l.ultimo;i++){
                if (it.numero < l.vetitem[i].numero){
                    pos = i;
                    break;
                }

            }
            //realocar
            string sentido;
            if (sentido == "ed"){
                for (int j=pos;j<l.ultimo;j++){
                    l.vetitem[j] = l.vetitem[j+1];
                }
            }
            else{
                for (int j=l.ultimo;j>=pos;j--){
                    l.vetitem[j] = l.vetitem[j-1];
                }
            }
            l.vetitem[pos] = it;
            l.ultimo++;


        }
    }
}
// verificar se um número informado pelo usuário pertence à uma lista;
int verificar(TListaA l, int c){
    bool achou = false;
    int pegaPos;

    if (estavazia1(l)){
        return -1;
    }
    else{
        for(int i=l.primeiro;i<l.ultimo && achou == false;i++){
            if(l.vetitem[i].numero == c){
                achou = true;
                pegaPos = i;
                // break; NÃO USAR! Modifique a condição acrescentando o teste novo do achou
            }
        }
        if(achou == true){
            cout << "achei o item " << c << endl;
            return pegaPos;
        }
        else{
            cout << "nao achei o item " << c << endl;
            return -1;

        }
    }
}

// remover um elemento de uma lista
void remover(int p,TListaA &l){
    if (estavazia1(l)){
        cout << "Nada para retirar. Lista Vazia." << endl;
    }
    else{
        string sentido;
        int pos;
        if (sentido == "ed"){
        for (int j=pos;j<l.ultimo;j++){
               l.vetitem[j] = l.vetitem[j+1];
        }
    }
    else{
        for (int j=l.ultimo;j>=pos;j--){
               l.vetitem[j] = l.vetitem[j-1];
        }
    }
        l.ultimo--;
    }
}
// mostrar os itens de uma lista
void mostrar(TListaA l){
    if (estavazia1(l)){
        cout << "Lista Vazia. Nada para mostrar!" << endl;
    }
    else{
        for (int i=l.primeiro; i<l.ultimo;i++){
            cout << "item " << i << ": " << l.vetitem[i].numero << endl;
        }
    }
}

// copiar os elementos de uma lista para outra lista;
void copiarLpL(TListaA l1, TListaA &l2){
    l2 = l1;
}
// concatenar duas listas numa outra lista;
void inserirNormal(item it, TListaA &l){
    if (estaCheia1(l)){
        cout << "Lista Cheia!" << endl;
    }
    else{
        l.vetitem[l.ultimo] = it;
        l.ultimo++;
    }
}
void concatenarListas(TListaA l1, TListaA l2, TListaA &l3){

    for (int i=l1.primeiro;i<l1.ultimo;i++){
        //l3.vetItens[i] = l1.vetItens[i]; // ISTO É UM ABSURDO!!!
        inserirNormal(l1.vetitem[i],l3);
    }
    //int desloc = l1.ultimo;
    for (int i=l2.primeiro;i<l2.ultimo;i++){
        //l3.vetItens[i+desloc] = l2.vetItens[i];// ISTO É UM ABSURDO!!!
        inserirNormal(l2.vetitem[i],l3);
    }
}
main(){
    setlocale(LC_ALL,"Portuguese");

    TListaA lista1, lista2, lista3, lista4;

    criarListaA(lista1);

    item aux;

    aux.numero = 5;
    inserirCrescente(aux,lista1);
    aux.numero = 4;
    inserirCrescente(aux,lista1);
    aux.numero = 7;
    inserirCrescente(aux,lista1);
    aux.numero = 2;
    inserirCrescente(aux,lista1);
    aux.numero = 9;
    inserirCrescente(aux,lista1);

    mostrar(lista1);

    verificar(lista1,7);

    verificar(lista1,8);

    remover(3,lista1);
    cout << "--mostrando lista 1" << endl;
    mostrar(lista1);
    cout << "--mostrando lista 2" << endl;
    mostrar(lista2);
    cout << "--mostrando lista 3" << endl;
    mostrar(lista3);
    cout << "--mostrando lista 4" << endl;
    mostrar(lista4);
    return 0;
}
