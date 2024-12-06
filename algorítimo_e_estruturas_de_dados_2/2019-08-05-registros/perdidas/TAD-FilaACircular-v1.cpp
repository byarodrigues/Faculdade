#include <iostream>
#include <clocale>
using namespace std;

// ESTA VERSÃO SE BASEIA NA IMPLEMENTAÇAO CIRCULAR PROPOSTA POR ZIVIANI.
// O PROBLEMA DE "NÃO CABER" APESAR DE TER POSIÇÃO LIVRE É RESOLVIDO.

// SESSÃO DE DECLARAÇÕES

const int maxTam = 5;

// ESTRUTURA

struct TFilaACircular{
    int vetItens[maxTam];
    int frente;
    int tras;
    int contItens; //criado por nós, por estarmos numerando o vetor a partir de zero
};

// OPERAÇÕES BÁSICAS
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
        cout << "Não posso enfileirar. Fila Cheia!" << endl;
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
        cout << "Não posso desenfileirar. Fila Vazia!" << endl;
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

    setlocale(LC_ALL,"Portuguese");//para acentuação e caracteres especiais

    TFilaACircular fila; //instanciação

    criarFilaVazia(fila); // prepara para o uso
    // não pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Trás: " << fila.tras << endl;

    enfileirar(fila,5);
    enfileirar(fila,7);
    enfileirar(fila,8);
    enfileirar(fila,3);
    enfileirar(fila,9);

    enfileirar(fila,14);
    mostrar(fila);

    //enfileirar(fila,14);

    // não pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Trás: " << fila.tras << endl;

    desenfileirar(fila);
    // não pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Trás: " << fila.tras << endl;

     enfileirar(fila,14);
      // não pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Trás: " << fila.tras << endl;

    desenfileirar(fila);
    // não pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Trás: " << fila.tras << endl;

    desenfileirar(fila);
    // não pode, lembra!!!
    cout << "Frente: " << fila.frente << "  |  Trás: " << fila.tras << endl;


    return 0;
}
