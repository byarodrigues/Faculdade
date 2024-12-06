#include <iostream>
#include <clocale>
#include <vector>
#include "header.h"
#include "mbtree.h"
#include "node.h"
#include "record.h"
#include "serialChar.h"
#include "serializable.h"
#include "typedfile.h"

using namespace std;

int main() {

    mbtree<int, 3> tree;
    int op;
    setlocale(LC_ALL, "Portuguese");
    vector<char> inserting = {'u', '<', 'd', 'e', 'i', '{', '!', 'X', '.', '4', 'r', 'J', '#', 'B', '7', 'x', ',', '?', '9', ';', 'Q', '8', 'I', 'P', 'C'};
    vector<char> removing = {'4', 'r', '#', ',', 'i', '<', 'e', '8', '9', 'C', '!', 'P'};
    typedFile<intSerial> arq("teste.dat", "TPG", 1);
    bool quit = false;

    if (arq.isOpen()) {
        cout << "Arquivo aberto com sucesso!\n\n";

        do {
            cout << "Selecione uma op��o:\n\n"
                 << "1. Inserir um caracter na �rvore\n"
                 << "2. Remover um caracter da �rvore\n"
                 << "3. Imprimir a �rvore completa\n"
                 << "4. Buscar um valor na �rvore\n"
                 << "5. Executar um conjunto de testes padronizados\n"
                 << "6. Sair\n\n"
                 << "Sua op��o: ";

            cin >> op;

            switch (op) {
                case 1:
                    cout << "Digite um caracter: ";
                    char value;
                    cin >> value;
                    tree.insert(value);
                    arq.insertRecord(intSerial(value));
                    break;
                case 2:
                    cout << "Digite um caracter que deseja remover do arquivo: ";
                    char valueToRemove;
                    cin >> valueToRemove;
                    tree.remove(valueToRemove);
                    arq.deleteRecord(arq.search(intSerial(valueToRemove)));
                    break;
                case 3:
                    cout << "�rvore completa:\n";
                    // Add code to print the complete tree
                    break;
                case 4:
                    cout << "Digite um valor para buscar na �rvore: ";
                    char searchValue;
                    cin >> searchValue;
                    if (tree.search(searchValue)) {
                        cout << "Valor encontrado na �rvore.\n";
                    } else {
                        cout << "Valor n�o encontrado na �rvore.\n";
                    }
                    break;
                case 5:
                    // Add code to execute a set of standardized tests
                    break;
                case 6:
                    cout << "Encerrando o programa... ";
                    arq.close();
                    cout << "conclu�do." << endl;
                    quit = true;
                    break;
                default:
                    cout << "Op��o inv�lida. Por favor, tente novamente.\n" << endl;
                    break;
            }

        } while (!quit);
    } else {
        cout << "N�o foi poss�vel abrir o arquivo! x_x" << endl;
        return 1;
    }

    return 0;
}
