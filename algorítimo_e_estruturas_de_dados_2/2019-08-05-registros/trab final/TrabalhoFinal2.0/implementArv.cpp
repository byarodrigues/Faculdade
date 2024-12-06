#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "bibliARV.h"
#include "structsbibli.h"
#include "bibliFILA.h"
using namespace std;
void criaArvVazia(TArvoreBin &a,string n){
    a.nome  = n;
    a.contItens  = 0;
    a.raiz = NULL;
}
void inserirArv(TArvoreBin &a,TNo *&no,TVacas x){
    if (no == NULL){
        no = new TNo;
        no->vaca = x;
        no->esq = NULL;
        no->dir = NULL;
        a.contItens++;
        if (a.raiz == NULL){
            a.raiz = no;
        }
    }
    else{
        if (x.codigo < no->vaca.codigo){ // chamada recursiva ESQ
            inserirArv(a,no->esq,x);
        }
        else{
            if (x.codigo > no->vaca.codigo){ // chamada recursiva DIR
                inserirArv(a,no->dir,x);
            }
            else{
                if (x.codigo == no->vaca.codigo){
                 }
            }
        }
    }
}
int lendoArq(string nomeArq, int quantTokens,TArvoreBin &a){ // esse procedimento serve para ler o aruivo e manda para uma arvore
    TVacas aux;                                                // ou seja semnpre a  arvore vai ser atualizada para ter todas as vacas que foram cadastradas
    fstream arq("vacas.txt");
    if (arq.is_open()){
        string registro, token;
        string valores[quantTokens];
        int i, j, contToken, contRegistro;

        contRegistro = 1;
        while (arq.good()){
            getline(arq,registro);
            if (registro.length() > 0){
                token = "";

                for (j=0; j < quantTokens;j++){
                    valores[j] = token;
                }

                i=0;
                contToken=0;
                while (i <= int(registro.length())){
                   if (registro[i] != ';') {
                        token = token + registro[i];
                    }
                    else{
                       valores[contToken] = token;

                       contToken++;
                       token = "";

                    }
                    i++;
                }
                valores[contToken] = token;
                for (j=0; j<9;j++){
                    if (j == 0){
                        aux.codigo = valores[j];
                    }
                    else{
                        if (j == 1){
                            aux.raca = valores[j];
                        }
                        else{
                            if (j==2){
                               for(int z = 0; z < 7; z++){
                                    if (z < 6){
                                        aux.litrosP[z] = valores[j];
                                    }
                                    else{
                                        aux.litrosP[z] = valores[j];
                                    }
                                    j++;
                               }
                            }
                        }
                    }

                }
                inserirArv(a,a.raiz,aux);
                contRegistro++;
            }
        }
    }
    else{
        cout << "Problemas com a abertura do arquivo!" << endl;
	return -1;
    }
    arq.close();
    return 0;
}
void pesquisar(TArvoreBin a,string c, TNo *&n){// procedimento usado para mostrar o perfil individual de cada vaca
    double aux;                                 // utilizando simplesmente o metodo de pesquisar na arvore
    if (n == NULL){
        cout << "Vaca não encontrada!!!" << endl;
    }
    else {
        if (c < n->vaca.codigo){
            pesquisar(a, c, n->esq);
        }
        else {
            if (c > n->vaca.codigo){
                pesquisar(a, c, n->dir);
            }
            else{

                cout<<"         -PERFIL DO ANIMAL:"<<endl;
                cout<<endl;
                cout<<"             ID: "<<n->vaca.codigo<<endl;
                cout<<"             Raça: "<<n->vaca.raca<<endl;
                for (int z = 0;z < 7;z++){
                    aux = aux + atoi(n->vaca.litrosP[z].c_str());
                }
                cout<<"             Litros Produzidos: "<<aux<<" L "<<endl;
                cout<<"             Ração consumida: "<<int(aux/3)<<" KG "<<endl;
            }
        }
    }

}
void relRaca(TNo *&no,string r){ // procedimento criado para mostrar o relatorio por raça, utilizando o metodo preOrdem de demostração da arvore
    double aux;
    aux = 0;

    if(no!=NULL){
        if(no->vaca.raca == r){
            aux =0;
            if ((r == "Gir")|| (r == "gir")){
                cout<<"             ID: "<<no->vaca.codigo<<endl;
            for(int i = 0; i < 7 ; i++){
                aux = aux + atoi(no->vaca.litrosP[i].c_str());
            }
            cout<<"             litros de leite Produzido: "<<aux<<" L"<<endl;
            cout<<"             Ração consumida: "<<int(aux/3)<<"KG DE Ração"<<endl;
            cout<<" "<<endl;
            cout<<" "<<endl;
        }else{
            if ((r == "Girolando")||(r == "girolando")){
                cout<<"             ID: "<<no->vaca.codigo<<endl;
            for(int i = 0; i < 7 ; i++){
                aux = aux + atoi(no->vaca.litrosP[i].c_str());
            }
                    cout<<"             litros de leite Produzido: "<<aux<<" L"<<endl;
                    cout<<"             Ração consumida: "<<int(aux/3)<<"KG DE Ração"<<endl;
                    cout<<" "<<endl;
                    cout<<" "<<endl;
            }
            else{
               if ((r == "Holandesa")|| (r == "holandesa")){
                    cout<<"             ID: "<<no->vaca.codigo<<endl;
                    for(int i = 0; i < 7 ; i++){
                    aux = aux + atoi(no->vaca.litrosP[i].c_str());
            }
                cout<<"                 litros de leite Produzido: "<<aux<<" L"<<endl;
                cout<<"             Ração consumida: "<<int(aux/3)<<"KG DE Ração"<<endl;
                cout<<" "<<endl;
                cout<<" "<<endl;
            }
            else{
                cout<<"                 Raça nao encontrada!!!"<<endl;
            }
        }
        }
        }
        relRaca(no->esq,r);
        relRaca(no->dir,r);
    }
}
void inserindoFila(TNo *&no,TFilaP &f){ // passando todas as vacas cadastradas para uma fila para mostrar toda a produção de leite com uma ordem crescente de seu codigo de cadastro
    if(no!=NULL){
        inserindoFila(no->esq,f);
        enfileirarVacas(f,no->vaca);
        inserindoFila(no->dir,f);
    }
}

