#include <iostream>
#include <clocale>
#include "biblio.h"  // caminho da biblioteca
#include "continhas.h"

using namespace std;

int main(){

    int num;

    cout << "Digite um valor inteiro positivo: ";
    cin >> num;

//    for (int i=1; i<=num;i++){
//        cout << i << endl;
//    }

    mostrar(num);

    cout << "Dobro: " << dobrar(num) << endl;

    return 0;
}
