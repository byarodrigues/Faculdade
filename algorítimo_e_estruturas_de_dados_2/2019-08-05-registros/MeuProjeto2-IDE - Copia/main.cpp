#include <iostream>
#include "continhas.h"

using namespace std;

int main()
{
    int a,b;

    cout << "Hello world!" << endl;

    cout << "Digite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de b: ";
    cin >> b;

    cout << "Soma: " << somar(a,b) << endl;

    cout << "Multiplicar: " << multiplicar(a,b) << endl;

    return 0;
}
