/*  AULA - 31/7/2019
    Demonstrar a implementação de registros
    Entidade: Pessoa, com nome, sexo e idade.
*/

// PARA CASA:
//  teste a manipulação de dados em um vetor de 5 alunos.


#include <iostream>
using namespace std;

// SESSÃO DE DECLARAÇÕES
struct TAluno{
    string nome;
    char sexo;
    int idade;
    double vetNotas[5];
};

int main(){

    //usando o TAluno
    TAluno aluno; // variável do tipo TPessoa

    cout << "=== MANIPULANDO VARIÁVEL ===" << endl;
    // atribuindo valores
    aluno.nome = "Gabriel";
    aluno.sexo = 'M';
    aluno.idade = 40;
    // notas deste aluno
    aluno.vetNotas[0] = 76;
    aluno.vetNotas[1] = 50;
    aluno.vetNotas[2] = 48;
    aluno.vetNotas[3] = 90;
    aluno.vetNotas[4] = 84;


    // acessando e mostrando
    cout << "Nome: " << aluno.nome << endl;
    cout << "Sexo: " << aluno.sexo << endl;
    cout << "Idade: " << aluno.idade << endl;
    cout << "Notas: " << endl;
    cout << "  Nota 1: " << aluno.vetNotas[0] << endl;
    cout << "  Nota 2: " << aluno.vetNotas[1] << endl;
    cout << "  Nota 3: " << aluno.vetNotas[2] << endl;
    cout << "  Nota 4: " << aluno.vetNotas[3] << endl;
    cout << "  Nota 5: " << aluno.vetNotas[4] << endl;

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
