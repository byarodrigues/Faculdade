/*  AULA - 31/7/2019
    Demonstrar a implementa��o de registros
    Entidade: Pessoa, com nome, sexo e idade.
*/

// PARA CASA:
//  teste a manipula��o de dados em um vetor de 5 alunos.


#include <iostream>
#include <clocale>
using namespace std;

// SESS�O DE DECLARA��ES

struct TEndereco{
    string rua;
    int num;
    string bairro;
    string cidade;
    string cep;
};

struct TAluno{
    string nome;
    char sexo;
    int idade;
    double vetNotas[5];
    TEndereco endereco; // usando a struct acima
};

int main(){

    setlocale(LC_ALL,"Portuguese");//para acentua��o e caracteres especiais

    TAluno vetAlunos[5]; //instancia��o
    int i,j;

    // entrada de dados
    for(i=0;i<5;i++){
        cout << "Dados do "<< i+1 << "� aluno: " << endl;
        cout << "  Nome: ";
        cin >> vetAlunos[i].nome;
        cout << "  sexo: ";
        cin >> vetAlunos[i].sexo;
        cout << "  idade: ";
        cin >> vetAlunos[i].idade;
        cout << "  Notas: " << endl;
        for (j=0;j<5;j++){
            cout << "     Nota "<< j+1 << ": ";
            cin >> vetAlunos[i].vetNotas[j];
        }
        // cadastrando os dados do endere�o
        cout << "Endere�o: " << endl;
        cout << "  Rua: ";
        cin >> vetAlunos[i].endereco.rua;
        cout << "  Num: ";
        cin >> vetAlunos[i].endereco.num;
        cout << "  Bairro: ";
        cin >> vetAlunos[i].endereco.bairro;
        cout << "  Cidade: ";
        cin >> vetAlunos[i].endereco.cidade;
        cout << "  Cep: ";
        cin >> vetAlunos[i].endereco.cep;
        //...
    }

    // sa�da dos dados
    cout << "=== MOSTRANDO OS DADOS ===" << endl;
    for(i=0;i<5;i++){
        cout << "Dados do "<< i+1 << "� aluno: " << endl;
        cout << "  Nome: " << vetAlunos[i].nome << endl;
        cout << "  Sexo: " << vetAlunos[i].sexo << endl;
        cout << "  Idade: " << vetAlunos[i].idade << endl;
        //...
        cout << "  Notas: " << endl;
        for (j=0;j<5;j++){
            cout << "     Nota "<< j+1 << ": " << vetAlunos[i].vetNotas[j] << endl;
        }
    }

    return 0;
}
