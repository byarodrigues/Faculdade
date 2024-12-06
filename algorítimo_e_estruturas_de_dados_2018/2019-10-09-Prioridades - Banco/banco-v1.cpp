#include <iostream>
#include <clocale>
using namespace std;

struct TCliente{
    int chave;
    string nome;
    int idade;
    bool gestante;
};

struct TCelula{
    TCliente item;
    TCelula *proximo;
};

struct TListaPriori{
    TCelula *primeiro;
    TCelula *ultimo;
    int contClientes;

};

struct TFila{
    TCelula *frente;
    TCelula *tras;
    int contClientes;
};

// OPERAÇÕES COM A LISTA
void criarLPVazia(TListaPriori &l){
    l.primeiro = new TCelula;
    l.ultimo = l.primeiro;
    l.contClientes = 0;
}

bool estaVaziaLP(TListaPriori l){
    return l.primeiro == l.ultimo;
}

void inserirDefault(TListaPriori &l, TCliente c){
    l.ultimo->proximo = new TCelula;
    l.ultimo = l.ultimo->proximo;
    l.ultimo->item = c;
    l.ultimo->proximo = NULL;
    l.contClientes++;
}

void inserirComPriori(TListaPriori &l, TCliente c){
    if(estaVaziaLP(l) || (c.idade < 60 && c.gestante == false)){
        inserirDefault(l,c);
        cout << "inseriu padrão" << endl;
    }
    else{ // idoso ou gestante
        cout << "entrou no else IDOSO ou GESTANTE" << endl;
        TCelula *pegaAnterior = NULL;
        if (c.idade >= 60){ // idoso
            cout << "entrou no if do IDOSO" << endl;
            // percorre a lista até achar onde inserir
            TCelula *celAux = l.primeiro;
            //TCelula *pegaAnterior = NULL;
            while (celAux->proximo != NULL && pegaAnterior==NULL){
                if(celAux->proximo->item.idade < 60){
                   // inserir o cara! ou pegar o anterior
                   pegaAnterior = celAux; // deixarei para fazer a inserção no final
                                          // pq usarei a mesma variável para gestante
                }
                celAux = celAux->proximo;
            }
            if (pegaAnterior == NULL){
                cout << "entrou no caso de só existir idosos na lista" << endl;
                inserirDefault(l,c);
            }
        }
        else{// gestante
            if (c.gestante==true){
                // percorre a lista até achar onde inserir
                TCelula *celAux = l.primeiro;

                while (celAux->proximo != NULL && pegaAnterior==NULL){
                    if(celAux->proximo->item.idade < 60 && celAux->proximo->item.gestante==false){
                       // inserir o cara! ou pegar o anterior
                       pegaAnterior = celAux; // deixarei para fazer a inserção no final
                                              // pq usarei a mesma variável para gestante
                    }
                    celAux = celAux->proximo;
                }
                if (pegaAnterior == NULL){
                    inserirDefault(l,c);
                }
            }
        }
        // aqui a gente insere o idoso ou a gestante
        cout << "chegou na inserção por prioridade" << endl;
        TCelula *novaCel= new TCelula; // ALOCANDO ESPAÇO PARA A NOVACEL
        novaCel->item = c;
        cout << novaCel->item.nome << endl;
        novaCel->proximo = pegaAnterior->proximo;
        pegaAnterior->proximo = novaCel;
    }

}

void mostraLP(TListaPriori l){
    if (estaVaziaLP(l)){
        cout << "Lista Vazia" << endl;
    }
    else{
        TCelula *celAux = l.primeiro->proximo;
        while (celAux != NULL){
            cout << "Chave: " << celAux->item.chave << endl;
            cout << "Nome: " << celAux->item.nome << endl;
            celAux = celAux->proximo;
        }
    }
}

void cadastrarCliente(TListaPriori &l){
    string resp = "S";
    string gestanteAux;
    TCliente c;
    int chave=1;

    while (resp=="S"){// ALTEREM PARA QUE SEJA POSSÍVEL NÃO CADASTRAR NINGUÉM
        c.chave = chave;
        cout << "Chave: " << c.chave << endl;
        cout << "Nome:  ";
        cin >> c.nome;
        cout << "Idade: ";
        cin >> c.idade;
        do{
            cout << "Gestante (S/N): ";
            cin >> gestanteAux;
            if (gestanteAux == "S"){
                c.gestante = true;
            }
            else{
                if (gestanteAux == "N"){
                    c.gestante = false;
                }
                else{
                    cout << "Burro(a), é S ou N!" << endl;
                }
            }
        } while (gestanteAux!="S" && gestanteAux!="N");
        chave++;
        inserirComPriori(l,c);
        cout << "Deseja cadastrar outro cliente? (S/N) ";
        cin >> resp;
    }
}

int main(){

    TListaPriori lista;
    criarLPVazia(lista);

    cadastrarCliente(lista);

    mostraLP(lista);
    cin ;

    return 0;
}
