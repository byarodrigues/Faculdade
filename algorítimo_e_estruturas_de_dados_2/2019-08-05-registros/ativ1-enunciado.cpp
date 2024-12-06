/*  AULA - 05/08/2019
    Reforçar a implementação de registros composto usando modularização.

Atividade 1:

Você participará de uma equipe que desenvolverá um programa para informatizar um banco,
fazendo o controle dos clientes e de suas contas. Neste primeiro momento, serão definidas
apenas as estruturas básicas e o cadastro de um cliente e sua respectiva conta.
Faça um programa que:
a. declare os registros TCliente e TConta, conforme descrição a seguir:
i. os dados de Cliente são: matrícula, nome, idade e conta
ii. os dados da Conta são: número, tipo e saldo. O tipo pode ser Poupança ou Conta Corrente
b. crie todas as variáveis necessárias para realizar o cadastro de 01 (um) cliente e sua conta;
c. crie um procedimento para realizar o cadastro;
d. crie um procedimento para mostrar os dados cadastrados.

*/
#include <iostream>
using namespace std;
struct TConta{
    int numero;
    string tipo;
    int saldo;
};

struct TCliente{
    int matricula;
    string nome;
    int idade;
    TConta co;

};

void cadastrar;{
    TCliente c;

    cout << "-- DADOS DO CLIENTE --" << endl;
    cout << " Nome: " ;
    cin >> c.nome;
    cout << " Matricula: ";
    cin >> c.matricula;
    cout << " Idade: ";
    cin >> c.idade;
    cout << "-- DADOS DA CONTA --" << endl;
    count << " Numero: ";
    cin >> c.co.numero;
    cout << " Tipo: ";
    cin >> c.co.tipo;
    cout << " Saldo: ";
    cin >> c.co.saldo;

}

void mostrar{
    cout << "-- MOSTRANDO DADOS DO CLIENTE --" << endl;
    count << "Nome: " << c.nome << endl;
    count << "Matricula: " << c.matricula << endl;
    count << "idade: " << c.idade << endl;
    count << "Dados da conta: " << endl;
    count << "numero: " << c.co.numero << endl;
    count << "tipo: " << c.co.tipo << endl;
    count << "saldo: " << c.co.saldo << endl;

}


int main(){
    setlocale(LC_ALL,"Portuguese");
    mostrar


return 0;
}
