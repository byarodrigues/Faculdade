#include <iostream>
#include <clocale>//bibilioteca usada para adicionar a lingugem Portugues no codigo;
#include <stdlib.h> // usada para o comando limpa tela ou pausar a execução;
#include <fstream>// manipulação de arquivo;
#include <cstdlib>//usada para converter tipos de variaveis Ex: string para double (que foi usada no codigo);
#include <string>
using namespace std;

int cad();//função para cadastro de vacas
void lercad();// procedimento para ler vacas cadastradas
void prod();// procedimento para a produção
int qtdLinhas();//função para contar

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int op,qtdVacas,tam;
    // MENU CONTEM 4 OPÇÕES ONDE QUANDO FOR DIGITADO 4 SERA O FIM DA EXCUÇÃO;
    while( op!=4 ){
        system("cls");
        cout<<"Bem Vindo"<<endl;
        cout<<"Gerenciamento de Produção de leite  "<<endl;
        cout<<" _Menu______________________________"<<endl;
        cout<<"| 1 - CADASTRO DE VACAS             |"<<endl;
        cout<<"| 2 - VER VACAS CADASTRADAS         |"<<endl;
        cout<<"| 3 - LEITE PRODUZIDO/RAÇÃO GASTA   |"<<endl;
        cout<<"| 4 - SAIR                          |"<<endl;
        cout<<"|___________________________________|"<<endl;
        cout<<"Escolha uma opção: ";
        cin>>op;
        //USANDO O SWITCH CASE PARA INTERAGIR COM O MENU;
        switch (op){
        case 1:
                cad();
                break;
        case 2:
            lercad();
            system("cls");
            break;
        case 3:
            prod();
            system("cls");
            break;
        case 4:
            system("cls");
            cout<<"Obrigado!!!"<<endl;
            system("pause");
            break;
        default:
            system("cls");
            cout<<"Opção invalida, escolha uma opcão de 1 a 4 "<<endl;
            system("pause");
        }
    }
    return 0;
}

//Procedimento para cadastrar os animais/

int cad(){//fuçao usada para cadastrar as vacas;
    system("cls");
    int l,c,op2,qtdVacas;
    char escolha;
    cout<<"Deseja apagar as vacas ja cadastradas?(S/N)";
    cin>>escolha;
    if (escolha == 'S' or escolha == 's'){
    system("cls");
    cout<<"Quantas vacas deseja cadastrar: ";
    cin>>qtdVacas;
    fstream arquivo; // fstream uma biblioteca usada para a manipulçõa de arquivos;
    remove("vacas.txt");//sempre quando entra ele irar apagar e criara outro arquivo;
    arquivo.open("vacas.txt",ios::app|ios::ate);//abrindo o aquivo em dodo de escrita;
    if(arquivo.is_open()){ //verificando se o aqruivo esta abetro;
            double escreve ;
            string id  = "";
            for (l=1;l<=qtdVacas;l++){     //for usado em uma contagem onde salavarar em cada linha do arquivo informações de um vaxa;
                system("cls");
                for (c=1;c<=8;c++){
                    if (c == 1){
                        cout<<"ID da vaca: ";
                        cin>>id;
                        arquivo<<id<<";";
                    }
                    if(c==2){
                        cout<<"A vaca de ID: "<<id<<" Produziu quantos litros de leite"<<endl;
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==3){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==4){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==5){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==6){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==7){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==8){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<"\n";
                    }
                }
            }
    }
    else{
        cout<<"Problemas no arquivo";
    }
    }
    else{// CASO O USUARIO NAO DESEJ APAGAR AS VACAS JA CADASTRADAS
    system("cls");
    cout<<"Quantas vacas deseja cadastrar: ";
    cin>>qtdVacas;
    fstream arquivo; // fstream uma biblioteca usada para a manipulçõa de arquivos;
    arquivo.open("vacas.txt",ios::app|ios::ate);
    //abrindo o aquivo em dodo de escrita;
    if(arquivo.is_open()){ //verificando se o aqruivo esta abetro;
            double escreve ;
            for (l=1;l<=qtdVacas;l++){     //for usado em uma contagem onde salavarar em cada linha do arquivo informações de um vaxa;
                for (c=1;c<=8;c++){
                    if (c == 1){
                        string id  = "";
                        cout<<"ID da vaca: ";
                        cin>>id;
                        arquivo<<id<<";";
                    }
                    if(c==2){
                        cout<<"A vaca de ID: "<<escreve<<" Produziu quantos litros de leite"<<endl;
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==3){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==4){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==5){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==6){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==7){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<";";
                    }
                    if(c==8){
                        cout<<c-1<<"º Dia: ";
                        cin>>escreve;
                        arquivo<<escreve<<"\n";
                    }
                }
            }
    }
    else{
        cout<<"Problemas no arquivo"<<endl;
    }
    arquivo.close();
    return op2;
    }

}
void lercad(){//Procedimento usado para leitura de vacas cadastradas;
   string escreve;
   string ler;
   int i,l,c;
   l = 1;//iniciando contador de dias;
   c = 0;//contador de posição do arquivo;
   if (qtdLinhas() != 1 ){
   ifstream arquivo; //usando a funçao ifstream da biblioteca fstream;
   arquivo.open("vacas.txt");
   if (arquivo.is_open()){
        while(getline(arquivo,ler)){ //aqui o codigo vai rodando de linha por linha ate chrga em seu final;
            escreve = "";
            for(i = 0; i< ler.size();i++){
                if (ler[i] != ';'){ //usado para ler o que esta escrito ate um ponto de marção nesse caso ';' ;
                    escreve = escreve + ler[i]; //quando chegar nesse ';' aramazena oque esta escrito em uma variavel;
                }
                else{
                    if (c == 0){
                    cout<<endl;
                    cout<<"A vaca de ID:"<<escreve<<endl;
                    escreve = "";
                    c++;
                    cout<<"leite produzido:"<<endl;
                    }
                    else{
                        cout<<l<<"º dia: "<<escreve<<" L"<<endl;
                        escreve = "";
                        l++;
                    }
                }
            }
            cout<<endl;
            cout<<endl;
            l = 1;//reiniciando dias
            c = 0;
        }
    }
    else{
     cout<<"problemas no arquivo"<<endl;
    }
    arquivo.close();
    }
    else{
        cout<<"Ainda nao há nenhuma vaca cadastradas!"<<endl;
    }
    system("pause");
   }
void prod(){  //Procedimento utilizado para mostra a produçao semanal;
    system("cls");
    if (qtdLinhas() != 1 ){
    string ler,gravar;
    int i,l,c;
    double soma,somaL;
    ifstream arquivo;  //ifstream é uma funçao da biblioteca fstream para leitura de arquivo de uma maneira simples;
    arquivo.open("vacas.txt");
    if(arquivo.is_open()){
        cout<<"Produçaão semanal:"<<endl;
        c = 1;
        while(getline(arquivo,ler)) {
            gravar = "";
            soma = 0;
            somaL = 0;
            for(i = 1; i < ler.size();i++){
                if(ler[i] != ';'){
                    gravar = gravar + ler[i];
                }
                else{
                    double xp = atof(gravar.c_str());
                    gravar = "";
                    somaL=somaL+xp;
                    soma = soma + (xp/3);
                }
            }
            cout<<"vaca de ID: 000"<<c<<endl;
            cout<<"Leite Produzido: "<<somaL<<"Litros"<<endl;
            cout<<"Ração consumida: "<<soma<<" KG"<<endl;
            c = c + 1;
        }
    }
    }
    else{
        cout<<"Ainda não ha vacas cadastradas!"<<endl;
    }
    system("pause");
}
int qtdLinhas(){//função usada para contar quantas linhas a no arquivo;
    string ler;
    int tam;
    fstream arquivo;
    arquivo.open("vacas.txt");
    while(!arquivo.eof()){ // estruta simples que vai pulaando a cada linha do bloco de notas e atrubuindo a uma variavel quantas vezes ela pulou
        getline(arquivo,ler);
        tam++;
    }
    arquivo.close();
    return tam;
}

