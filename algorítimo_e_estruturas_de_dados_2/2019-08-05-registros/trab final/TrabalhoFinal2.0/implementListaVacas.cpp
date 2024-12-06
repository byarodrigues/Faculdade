#include "bibliLISTAVACAS.h"
#include <iostream>
#include <string>
#include <fstream> // biblioteca utilizada para a manipulçao do arquivo
#include "bibliARV.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;


void criarListaVazia(TlistaVacas &l){
    l.primeiro = new TCelula;
    l.ultimo = l.primeiro;
    l.primeiro->proximo = NULL;
}
bool listaVazia(TlistaVacas l){
    return l.ultimo == l.primeiro;
}
void inserirLista(TlistaVacas l,TVacas x){
    l.ultimo->proximo = new TCelula;
    l.ultimo = l.ultimo->proximo;
    l.ultimo->vaca = x;
    l.ultimo->proximo = NULL;
    escreverArq(l); // sempre quando eu acabo de adicionar uma vaca sempre passo pro arquivo direto para evitar erros;
}
void inserirLista2(TlistaVacas &l,TVacas x){
    l.ultimo->proximo = new TCelula;
    l.ultimo = l.ultimo->proximo;
    l.ultimo->vaca = x;
    l.ultimo->proximo = NULL;
}
void inserir(TlistaVacas l,TlistaVacas l2){ // sempre que utilizo esse procedimento nao passo uma lista por referencia porque se eu cadastrar mais de uma vez com o programa berto pode copiar itens repitidos pro arquivo
    TVacas x;
    bool e = false;
    cout<<"             -CADASOTRO DE VACA: "<<endl;
    cout<<"                 ID: ";
    cin>>x.codigo;
    while (verificaLista(x.codigo,l2) == true){
        cout<<"                 ID: ";
        cin>>x.codigo;
    }
    cout<<"                 Raça: ";
    cin>>x.raca;
    while ((x.raca != "Gir" )&& (x.raca != "gir") && (x.raca != "Girolando") && (x.raca != "girolando") && (x.raca != "Holandesa") && (x.raca != "holandesa")){
        cout <<"                Raça nao pode ser cadastrada!!  Raças que podem ser cadastradas : Gir , Girolando, Holandesa"<<endl;// nao deixa cadastrar vacas de outra raça a nao ser as pre definidas
        cout<<"             Raça: ";
        cin>>x.raca;
    }
    for (int z = 0;z<7;z++){
        cout<<"                 Litros Produzidos "<<z+1<<"º Dia:";
        cin>>x.litrosP[z];
    }
    inserirLista(l,x); // passando o objeto vaca para a lista
}
int escreverArq(TlistaVacas l){ // função criada para escrever no arquivo
    int i;
    string reg = "";
    fstream arq("vacas.txt",ios::ate|ios::in|ios::out);
    TCelula *celAux;
    celAux = l.primeiro->proximo;
    while (celAux != NULL){
        if (arq.is_open()){
            for (i=0; i<9;i++){ // ate nove pelo fato de querer quarda somente nove informaçoes sobre a vaca
                if (i == 0){
                    reg = reg + celAux->vaca.codigo + ";";
                }
                else{
                        if (i == 1){
                        reg = reg + celAux->vaca.raca + ";";
                        }
                        else{
                            if ( i > 1){
                                for(int z = 0;z < 7; z++){ // for criado para pegar os dias que cada vaca produziu
                                    if(z<6){
                                        reg = reg + celAux->vaca.litrosP[z]+";";
                                    }
                                    else{
                                        reg = reg + celAux->vaca.litrosP[z]+"\n"; // ultimo ccaso para pular para liha de baixo do arquivo de texto
                                    }
                                    i++;
                                }
                            }
                        }
                }
            }
            arq << reg;
            arq.close();
            cout << "Vaca cadastrada com sucesso!" << endl;
            return 0;
        }
        else{
            cout << "Problemas com o arquivo!" << endl;
            return -1;
        }
        celAux = celAux->proximo;
    }
}
int lendoArqLista(string nomeArq, int quantTokens,TlistaVacas &l){// uso essa lista para ajudar a verificar se ja existe o codigo em alguma vaca cadastrada
    TVacas aux;
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
                inserirLista2(l,aux);
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
bool verificaLista(string cd,TlistaVacas l2){// usado para sempre que inserir um ID ele verificar se ja existe alguma vaca com esse id
    TCelula *celAux = l2.primeiro->proximo;
    while (celAux !=NULL){
        if (cd == celAux->vaca.codigo){
            system("cls");
            cout<<"             codigo ja existe tente outro: "<<endl;
           return true;
        }
        celAux = celAux->proximo;
    }
}
//void ordenaLista(TlistaVacas &l){
//    TVacas aux;
//    TCelula *celAux = l.primeiro->proximo;
//    TCelula *celAux2 ;
//    while (celAux != NULL){
//    if (celAux->vaca.litrosP < celAux->proximo->vaca.litrosP){
//        aux = celAux->vaca;
//    }
//    celAux = celAux ->proximo;
//    }
//}
//void mostrarLista(TlistaVacas l){
//    TCelula *aux = l.primeiro->proximo;
//    while (aux != NULL){
//        cout<<aux->vaca.litrosP;
//        aux = aux->proximo;
//    }
//}
