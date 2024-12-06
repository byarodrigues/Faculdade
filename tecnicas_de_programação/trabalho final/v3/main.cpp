/********************************************************
 * main.cpp - Trabalho - Árvore B                       *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/
#include <iostream>
#include "mbtree.h"
#include "btree_node.h"
#include "typedfile.h"

int main() {
    // Criação e abertura do arquivo de dados
    typedFile<char> dataFile;  // Usar char para consistência com a árvore B
    dataFile.open("teste.dat", "tipo_do_no", 1, std::ios::in | std::ios::out | std::ios::binary);

    mbtree<char, 3> mbtree;

    if (!dataFile.isOpen()) {
        std::cerr << "Erro ao abrir o arquivo de dados." << std::endl;
        return 1;
    }

    char testKeysInsert[] = {'u', '<', 'd', 'e', 'i', '{', '!', 'X', '.', '4', 'r', 'J', '#', 'B', '7', 'x', ',', '?', '9', ';', 'Q', '8', 'I', 'P', 'C'};
    char testKeysRemove[] = {'4', 'r', '#', ',', 'i', '<', 'e', '8', '9', 'C', '!', 'P'};
    char value;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Inserir valor na árvore B\n";
        std::cout << "2. Remover valor da árvore B\n";
        std::cout << "3. Imprimir árvore completa\n";
        std::cout << "4. Buscar valor na árvore B\n";
        std::cout << "5. Executar conjunto de testes padronizados\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha uma opção: ";

        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cout << "Opção inválida. Tente novamente.\n";
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
                mbtree.insert(value);
                std::cout << "Valor inserido com sucesso.\n";
                break;

            case 2:
                std::cout << "Digite o valor a ser removido da árvore B: ";
                std::cin >> value;
                mbtree.remove(value);
                std::cout << "Valor removido com sucesso.\n";
                break;

            case 3:
                std::cout << "Árvore B completa:\n";
                mbtree.print();
                break;

            case 4:
                std::cout << "Digite o valor a ser buscado na árvore B: ";
                std::cin >> value;

                if (mbtree.search(mbtree.getRoot(), value) != -1) {
                    std::cout << "O valor está na árvore B.\n";
                } else {
                    std::cout << "O valor não está na árvore B.\n";
                }
                break;

            case 5: {
                std::cout << "Executando conjunto de testes padronizados:\n";

                // Inserir na árvore B e imprimir estado atual
                for (char key : testKeysInsert) {
                    mbtree.insert(key);
                    std::cout << "Inserindo " << key << ": ";
                    mbtree.print();
                    std::cout << "\n";
                }

                // Remover da árvore B e imprimir estado atual
                for (char key : testKeysRemove) {
                    mbtree.remove(key);
                    std::cout << "Removendo " << key << ": ";
                    mbtree.print();
                    std::cout << "\n";
                }

                break;
            }

            case 6:
                std::cout << "Encerrando o programa.\n";
                break;
        }

    } while (choice != 6);

    dataFile.close();

    return 0;
}

