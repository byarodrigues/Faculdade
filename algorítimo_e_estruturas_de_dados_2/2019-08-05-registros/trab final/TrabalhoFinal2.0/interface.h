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
    cout<<"              -ACOMPANHAMENTO DE PRODUÇÃO DE LEITE-"<<endl;
    cout<<"             |                                     |"<<endl;
    cout<<"             | 1- Cadastrar Vaca                   |"<<endl;
    cout<<"             | 2- Relatório Individual             |"<<endl;
    cout<<"             | 3- Relatório semanal                |"<<endl;
    cout<<"             | 4- Relatório por raça               |"<<endl;
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
    cout<<"             Escolha uma opção: ";
    cin>>opc;
    switch (opc){ // utilizando o switch case para a navegação pelo profgrama
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
            cout<<"             ID da vaca que deseja mostrar suas informações: ";
            cin>>id;
            pesquisar(a,id,a.raiz);
            system("pause");
        }
        break;
        case 3: // mostra a produção de leite durante toda semana
        system("cls");
            criarFilaPVazia(f);
            inserindoFila(a.raiz,f);
            cout<<"         -PRODUÇÃO DE LEITE DURANTE A SEMANA: "<<endl;
            mostrar(f);
        system("pause");
        break;
        case 4:{ //  ele mostra o relatorio por raça
            lendoArq("vacas.txt",9,a);
            string r;
            system("cls");
            cout<<"Nome da raça para ler o relatorio: ";
            cin>>r;
            system("cls");
            cout<<"         -PERFIL DE PRODUÇÃO POR RAÇA: "<<endl;
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
