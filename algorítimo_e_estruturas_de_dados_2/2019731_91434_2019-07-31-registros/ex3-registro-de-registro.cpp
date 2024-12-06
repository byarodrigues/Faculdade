/*  AULA - 31/7/2019
    Demonstrar a implementação de registros composto por registro.
    Entidade: Pessoa, com nome, sexo e idade.
                Acrescentar os campos de endereço: rua, num, bairro, cidade e cep
*/

// PARA CASA: manipular, na FORMA2, um conjunto de 5 pessoas.

#include <iostream>
using namespace std;

// SESSÃO DE DECLARAÇÕES

// FORMA 1
struct TPessoa{
    string nome;
    char sexo;
    int idade;
    string rua;
    int num;
    string bairro;
    string cidade;
    string cep;
};

//FORMA 2
// primeiro, o struct TEndereco que será usado por TPessoa
struct TEndereco{
    string rua;
    int num;
    string bairro;
    string cidade;
    string cep;
};

struct TPessoaComp{
    string nome;
    char sexo;
    int idade;
    TEndereco endereco;
};


int main(){

    //usando o TPessoa
    TPessoa p; // variável do tipo TPessoa

    cout << "=== MANIPULANDO VARIÁVEL da FORMA 1 ===" << endl;
    // atribuindo valores
    p.nome = "Gabriel";
    p.sexo = 'M';
    p.idade = 40;
    p.rua = "Rua X";
    p.num = 480;
    p.bairro = "Candola";
    p.cidade = "Bambui";
    p.cep = "38900-000";

    // acessando e mostrando
    cout << "Nome: " << p.nome << endl;
    cout << "Sexo: " << p.sexo << endl;
    cout << "Idade: " << p.idade << endl;
    cout << "Endereço: " << endl;
    cout << "  Rua: " << p.rua << endl;
    cout << "  num: " << p.num << endl;
    cout << "  Bairro: " << p.bairro << endl;
    cout << "  Cidade: " << p.cidade << endl;
    cout << "  CEP: " << p.cep << endl;


    //usando o TPessoaComp
    TPessoaComp p2; // variável do tipo TPessoaComp

    cout << "=== MANIPULANDO VARIÁVEL da FORMA 2 ===" << endl;
    // atribuindo valores
    p2.nome = "Gabriel";
    p2.sexo = 'M';
    p2.idade = 40;
    p2.endereco.rua = "Rua X"; // acessando o segundo nível
    p2.endereco.num = 480;
    p2.endereco.bairro = "Candola";
    p2.endereco.cidade = "Bambui";
    p2.endereco.cep = "38900-000";

    // acessando e mostrando
    cout << "Nome: " << p2.nome << endl;
    cout << "Sexo: " << p2.sexo << endl;
    cout << "Idade: " << p2.idade << endl;
    cout << "Endereço: " << endl;
    cout << "  Rua: " << p2.endereco.rua << endl;
    cout << "  num: " << p2.endereco.num << endl;
    cout << "  Bairro: " << p2.endereco.bairro << endl;
    cout << "  Cidade: " << p2.endereco.cidade << endl;
    cout << "  CEP: " << p2.endereco.cep << endl;




    return 0;
}
