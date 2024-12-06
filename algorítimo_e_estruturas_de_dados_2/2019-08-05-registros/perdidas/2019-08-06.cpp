/*  AULA - 31/7/2019
    Demonstrar a implementação de registros
    Entidade: Pessoa, com nome, sexo e idade.
*/

#include <iostream>
using namespace std;

// SESSÃO DE DECLARAÇÕES
struct TPessoa{
    string nome;
    char sexo;
    int idade;
};

int main(){

    //usando o TPessoa
    TPessoa p; // variável do tipo TPessoa

    cout << "=== MANIPULANDO VARIÁVEL ===" << endl;
    // atribuindo valores
    p.nome = "Gabriel";
    p.sexo = 'M';
    p.idade = 40;

    // acessando e mostrando
    cout << "Nome: " << p.nome << endl;
    cout << "Sexo: " << p.sexo << endl;
    cout << "Idade: " << p.idade << endl;

    // vetor de pessoas

    cout << "=== ALIMENTANDO O VETOR ===" << endl;
    TPessoa vetPessoas[5];
    int i;

    for (i=0;i<3;i++){
        cout << "Pessoa " << i+1 << ":" << endl;
        cout << "  Nome: ";
        cin >> vetPessoas[i].nome;
        cout << "  Sexo(M/F): ";
        cin >> vetPessoas[i].sexo;
        cout << "  Idade: ";
        cin >> vetPessoas[i].idade;
    }

    // mostrando o vetor

    cout << "=== MOSTRANDO O VETOR ===" << endl;

    for (i=0;i<3;i++){
        cout << "Nome: " << vetPessoas[i].nome << endl;
        cout << "Sexo: " << vetPessoas[i].sexo << endl;
        cout << "Idade: " << vetPessoas[i].idade << endl;
    }





    return 0;
}
