#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "bibliARV.h"
#include "bibliLISTAVACAS.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
void interface1(){
    cout<<"              -ACOMPANHAMENTO DE PRODU��O DE LEITE-"<<endl;
    cout<<"             |                                     |"<<endl;
    cout<<"             | 1- Cadastrar Vaca                   |"<<endl;
    cout<<"             | 2- Relat�rio Individual             |"<<endl;
    cout<<"             | 3- Relat�rio semanal                |"<<endl;
    cout<<"             | 4- Relat�rio por ra�a               |"<<endl;
    cout<<"             | 5- Sair                             |"<<endl;
    cout<<"             |                                     |"<<endl;
    cout<<"              -------------------------------------"<<endl;
}
void menu(TlistaVacas l,TArvoreBin &a,TFilaP &f,TlistaVacas &l2){
    int opc;
    lendoArq("vacas.txt",9,a);//preencho a biblioteca com o arquivo
    while(opc != 5){
    system("cls");
    interface1();
    lendoArq("vacas.txt",9,a);
    cout<<"             Escolha uma op��o: ";
    cin>>opc;
    switch (opc){ // utilizando o switch case para a navega��o pelo profgrama
        case 1: // caso o usuario queira cadatrar uma vaca
            system("cls");
            lendoArqLista("vacas.txt",9,l2);// passo tudo q estar no arquivo  pra lista
            inserir(l,l2); //cadastro mais uma vaca
            system("pause");
        break;
        case 2:{ // mostrar o rellatorio individual de cada vaca
            lendoArq("vacas.txt",9,a);
            string id;
            system("cls");
            cout<<"             ID da vaca que deseja mostrar suas informa��es: ";
            cin>>id;
            pesquisar(a,id,a.raiz);
            system("pause");
        }
        break;
        case 3: // mostra a produ��o de leite durante toda semana
        system("cls");
            criarFilaPVazia(f);
            inserindoFila(a.raiz,f);
            cout<<"         -PRODU��O DE LEITE DURANTE A SEMANA: "<<endl;
            mostrar(f);
        system("pause");
        break;
        case 4:{ //  ele mostra o relatorio por ra�a
            lendoArq("vacas.txt",9,a);
            string r;
            system("cls");
            cout<<"Nome da ra�a para ler o relatorio: ";
            cin>>r;
            system("cls");
            cout<<"         -PERFIL DE PRODU��O POR RA�A: "<<endl;
            relRaca(a.raiz,r);
            system("pause");
        }
        break;
        case 5:
            system("cls");
            cout<<"Obrigado!!!"<<endl;
            system("pause");
        break;
        default:
            system("pause");
    }
}
}
#endif // INTERFACE_H_INCLUDED
