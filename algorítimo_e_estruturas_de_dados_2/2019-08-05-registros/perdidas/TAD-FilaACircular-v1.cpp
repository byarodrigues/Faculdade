#include <iostream>
#include <clocale>
using namespace std;

// ESTA VERS�O SE BASEIA NA IMPLEMENTA�AO CIRCULAR PROPOSTA POR ZIVIANI.
// O PROBLEMA DE "N�O CABER" APESAR DE TER POSI��O LIVRE � RESOLVIDO.

// SESS�O DE DECLARA��ES

const int maxTam = 5;

// ESTRUTURA

struct TFilaACircular{
    int vetItens[maxTam];
    int frente;
    int tras;
    int contItens; //criado por n�s, por estarmos numerando o vetor a partir de zero
};

// OPERA��ES B�SICAS
void criarFilaVazia(TFilaACircular &f){
    f.frente = 0;
    f.tras = f.frente;
    f.contItens = 0; // quantidade
}

bool estaVazia(TFilaACircular f){
    //return f.frente == f.tras;
    //ou
    return f.contItens == 0;
}

bool estaCheia(TFilaACircular f){
    //return f.tras >= maxTam; PROBLEMA!!!
    return f.contItens == maxTam;
}

void enfileirar(TFilaACircular &f, int x){
    //if (estaCheia(f)){

    //if((f.tras+1) % maxTam == f.frente){ PROBLEMA
    if (estaCheia(f)){
        cout << "N�o posso enfileirar. Fila Cheia!" << endl;
    }
    else{
        f.vetItens[f.tras] = x;
        //f.tras++; // INCREMENTAR
        f.tras = (f.tras+1) % maxTam;
        f.contItens++;
    }
}

void desenfileirar(TFilaACircular &f){
    if (estaVazia(f)){
        cout << "N�o posso desenfileirar. Fila Vazia!" << endl;
    }
    else{
        //f.frente++; PROBLEMA
        f.frente = (f.frente+1) % maxTam;
        f.contItens--;
    }
}


// PARA CASA: mostrar!!!
void mostrar(TFilaACircular f){

    cout << "=== MOSTRANDO A FILA ===" << endl;
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

    TFilaACircular fila; //instancia��o

    criarFilaVazia(fila); // prepara para o uso
    // n�o pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Tr�s: " << fila.tras << endl;

    enfileirar(fila,5);
    enfileirar(fila,7);
    enfileirar(fila,8);
    enfileirar(fila,3);
    enfileirar(fila,9);

    enfileirar(fila,14);
    mostrar(fila);

    //enfileirar(fila,14);

    // n�o pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Tr�s: " << fila.tras << endl;

    desenfileirar(fila);
    // n�o pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Tr�s: " << fila.tras << endl;

     enfileirar(fila,14);
      // n�o pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Tr�s: " << fila.tras << endl;

    desenfileirar(fila);
    // n�o pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Tr�s: " << fila.tras << endl;

    desenfileirar(fila);
    // n�o pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Tr�s: " << fila.tras << endl;


    return 0;
}
