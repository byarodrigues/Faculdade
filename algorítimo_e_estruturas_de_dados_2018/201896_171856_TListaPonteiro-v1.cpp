#include <iostream>
#include <clocale>
using namespace std;

// VERSAO 1 - LISTA DINAMICAMENTE ENCADEADA POR PONTEIROS
// Por: Gabriel da Silva
//
// TAREFA: comente o c�digo a seguir, demonstrando o seu entendimento sobre cada linha



// ESTRUTURAS
struct TItem{
    int valor;
};

struct TCelula{
    TItem item;
    TCelula *proximo;
};

struct TListaP{
    TCelula *primeiro;
    TCelula *ultimo;
};


// OPERA��ES B�SICAS
void criarLista(TListaP &l){
    l.primeiro = new TCelula;
    l.ultimo = l.primeiro;
    l.primeiro->proximo = NULL;
    // apenas did�tico:
    cout << "Endere�o da c�lula primeiro:    " << l.primeiro << endl;
    cout << "Endere�o da c�lula ultimo:      " << l.ultimo << endl;
    cout << "Pr�ximo de qualquer um deles:   " << l.primeiro->proximo << endl;
}
// -> separador de campo quando � ponteiro!

bool estaVazia(TListaP l){
    return l.primeiro == l.ultimo;
}
// "moram no mesmo lugar?"

void inserir(TItem x, TListaP &l){
    l.ultimo->proximo = new TCelula;
    // ->proximo guardar� o end. mem. da nova c�lula,
    // por isso usa-se a este separador de campos (liga��o)
    l.ultimo = l.ultimo->proximo;
    l.ultimo->item = x;
    l.ultimo->proximo = NULL;
    // a linha abaixo � apenas DID�TICA, para eu demonstrar o endere�o
    // da nova c�lula criada!
    //cout << "Endere�o da c�lula criada agora: " << l.ultimo << endl;
    cout << "Inseriu:                               " << x.valor << endl;
    cout << "Endere�o da c�lula ultimo:             " << l.ultimo << endl;
    cout << "Endere�o da c�lula primeiro n�o muda:  " << l.primeiro << endl;
}

void mostrarLista(TListaP l)
{
    TCelula *pCelAux;

    pCelAux = l.primeiro->proximo;

    cout << "=== MOSTRANDO ITENS DA LISTA ===" << endl;
    while (pCelAux != NULL)
    {
        cout << "Endere�o apontado pelo pCelAux: " << pCelAux << endl;
        cout << "Valor dentro da C�lula: " << pCelAux->item.valor << endl;
        pCelAux = pCelAux->proximo;
    }
}

int contarItens(TListaP l)
{
    TCelula *pCelAux;
    pCelAux = l.primeiro->proximo;
    int cont = 0;

    cout << "=== CONTANDO OS ITENS DA LISTA ===" << endl;
    while (pCelAux != NULL)
    {
        cont++;
        pCelAux = pCelAux->proximo;
    }
    return cont;
}

int main(){

    setlocale(LC_ALL,"Portuguese");
    TListaP lista;
    criarLista(lista);

    if (estaVazia(lista)){
        cout << "Lista Vazia!" << endl;
    }
        else{
            cout << "Lista possui elementos!" << endl;
    }

    TItem itemAux;
    itemAux.valor = 5;
    inserir(itemAux,lista);

    itemAux;
    itemAux.valor = 7;
    inserir(itemAux,lista);

    cout << "Endere�o do pr�x do primeiro:  " << lista.primeiro->proximo << endl;
    cout << "Endere�o do pr�x do ultimo:  " << lista.ultimo->proximo << endl;

    mostrarLista(lista);
    cout << "A lista possui " << contarItens(lista) << " itens." << endl;
    cout << "End da Ultima Celula: " << lista.ultimo << endl;

    return 0;
}
