#include <iostream>
#include <clocale>
#include <stdlib.h> // para usar o system!
using namespace std;

void menu(string &l,string &l2, string &l3){

    int opcao;

    while (opcao != 5) {
        system("cls");
        cout << "===============================================================" << endl;
        cout << "|                   ATIVIDADE 3 -  QUESTÃO 1                  |" << endl;
        cout << "|                    Prof. Gabriel da Silva                   |" << endl;
        cout << "===============================================================" << endl;
        cout << "    MENU DE OPERAÇÕES: " << endl;
        cout << "       1 - Dizer 'Olá, Mundo!'" << endl;
        cout << "       2 - Testar" << endl;
        cout << "       3 - ..." << endl;
        cout << "       4 - ..." << endl;
        cout << "       5 - Sair" << endl;

        cout << "       Digite a opção:     ";
        cin >> opcao;

        switch (opcao){
            case 1:
                cout << "Olá, Mundo!" << endl;
                break;
            case 2:
                //...
                l = "gabriel";
                break;
            case 3:
                //...
                break;
            case 4:
                //...
                break;
            case 5:
                //...
                break;
        }
        system("pause");
        system("cls");
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    string lista, lista2,lista3;

    menu(lista,lista2,lista3);
    cout << lista;

    return 0;
}
