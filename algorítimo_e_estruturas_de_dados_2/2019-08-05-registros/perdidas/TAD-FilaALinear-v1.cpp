#include <iostream>
#include <clocale>
using namespace std;

// ESTA VERS�O SE BASEIA NA IMPLEMENTA�AO DA LISTA LINEAR.
// ENTRETANTO, APRESENTA UM S�RIO PROBLEMA!

// SESS�O DE DECLARA��ES

const int maxTam = 5;

// ESTRUTURA

struct TFilaALinear{
    int vetItens[maxTam];
    int frente;
    int tras;
};

// OPERA��ES B�SICAS
void criarFilaVazia(TFilaALinear &f){
    f.frente = 0;
    f.tras = f.frente;
}

bool estaVazia(TFilaALinear f){
    return f.frente == f.tras;
}

bool estaCheia(TFilaALinear f){
    return f.tras >= maxTam;
}

void enfileirar(TFilaALinear &f, int x){
    if (estaCheia(f)){
        cout << "N�o posso enfileirar. Fila Cheia!" << endl;
    }
    else{
        f.vetItens[f.tras] = x;
        f.tras++;
    }
}

void desenfileirar(TFilaALinear &f){
    if (estaVazia(f)){
        cout << "N�o posso desenfileirar. Fila Vazia!" << endl;
    }
    else{
        f.frente++;
    }
}

void mostrar(TFilaALinear f){
    if (estaVazia(f)){
        cout << "Nada para mostrar. Fila Vazia!" << endl;
    }
    else{
        for(int i=f.frente;i<f.tras;i++){
            cout << "Pos: " << i << ": " << f.vetItens[i] << endl;
        }
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");//para acentua��o e caracteres especiais

    TFilaALinear fila; //instancia��o

    criarFilaVazia(fila); // prepara para o uso
    // n�o pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Tr�s: " << fila.tras << endl;

    enfileirar(fila,5);
    enfileirar(fila,7);
    enfileirar(fila,8);
  //  enfileirar(fila,3);
  //  enfileirar(fila,9);

    mostrar(fila);

    //enfileirar(fila,14);

    // n�o pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Tr�s: " << fila.tras << endl;

    desenfileirar(fila);

    mostrar(fila);

    enfileirar(fila,14);

    mostrar(fila);

    enfileirar(fila,25);

    enfileirar(fila,32);

    mostrar(fila);
    return 0;
}
