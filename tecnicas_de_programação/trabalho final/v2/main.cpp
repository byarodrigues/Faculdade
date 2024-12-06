/********************************************************
 * main.cpp - Trabalho - Árvore B                       *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

#include <iostream>
#include "mbtree.h"
int main() {
    mbtree<char, 3> tree;  //tipo de dado desejado.

    char testKeysInsert[] = {'u', '<', 'd', 'e', 'i', '{', '!', 'X', '.', '4', 'r', 'J', '#', 'B', '7', 'x', ',', '?', '9', ';', 'Q', '8', 'I', 'P', 'C'};
    char testKeysRemove[] = {'4', 'r', '#', ',', 'i', '<', 'e', '8', '9', 'C', '!', 'P'};
    char value;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Inserir valor na arvore B\n";
        std::cout << "2. Remover valor da arvore B\n";
        std::cout << "3. Imprimir arvore completa\n";
        std::cout << "4. Buscar valor na arvore B\n";
        std::cout << "5. Executar conjunto de testes padronizados\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> choice;

        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cout << "Opcao invalida. Tente novamente.\n";
            std::cin.clear();  // Limpa o estado de erro

            // Ignora caracteres inválidos até encontrar uma nova linha
            while (std::cin.get() != '\n') {
                continue;
            }
        }

        switch (choice) {
            case 1:
                std::cout << "Digite o valor a ser inserido na árvore B: ";
                std::cin >> value;
                tree.insert(value);
                std::cout << "Valor inserido com sucesso.\n";
                break;

            case 2:
                std::cout << "Digite o valor a ser removido da árvore B: ";
                std::cin >> value;
                tree.remove(value);
                std::cout << "Valor removido com sucesso.\n";
                break;

            case 3:
                std::cout << "Árvore B completa:\n";
                tree.print();
                break;

            case 4:
                std::cout << "Digite o valor a ser buscado na árvore B: ";
                std::cin >> value;

                if (tree.search(value) != -1) {
                    std::cout << "O valor está na árvore B.\n";
                } else {
                    std::cout << "O valor não está na árvore B.\n";
                }
                break;

            case 5: {
                std::cout << "Executando conjunto de testes padronizados:\n";

                // Inserir na árvore B e imprimir estado atual
                for (char key : testKeysInsert) {
                    tree.insert(key);
                    std::cout << "Inserindo " << key << ": ";
                    tree.print();
                    std::cout << "\n";
                }

                // Remover da árvore B e imprimir estado atual
                for (char key : testKeysRemove) {
                    tree.remove(key);
                    std::cout << "Removendo " << key << ": ";
                    tree.print();
                    std::cout << "\n";
                }

                break;
            }

            case 6:
                std::cout << "Encerrando o programa.\n";
                break;

        }

    } while (choice != 6);

    return 0;
}
