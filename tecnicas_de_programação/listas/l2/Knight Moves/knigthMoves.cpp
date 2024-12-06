// * Movimentos do Cavalo: Bellman-Ford *//

/*
Peter is doing a research on the Traveling Knight Problem (TKP) where you have to find the shortest closed tour of knight moves that visits each square of a given set of n squares on a chessboard exactly once. He thinks that the most difficult part of the problem is determining the smallest number of knight moves between two given squares and that, once you have accomplished this, finding the tour would be easy.
Of course you know that it is vice versa. So you must offer him a program that solves the "difficult" part.
Your job is to write a program that takes two squares a and b as input and then determines the number of knight moves on a shortest route from a to b.

Input
The input file will contain one or more test cases. Each test case consists of one line containing two squares separated by one space. A square is a string consisting of a letter (a-h) representing the column and a digit (1-8) representing the row on the chessboard. See the figure above.

Output
For each test case, print one line saying"To get from xx to yy takes n knight moves.".

BELLMAN-FORD(G, w, s)
1   INITIALIZE-SINGLE-SOURCE(G, s)
2   for i = 1 to |G.V| - 1
3      for each edge (u, v) ∈  G.E
4         RELAX(u, v, w)
5   for each edge (u, v) ∈ G.E
6      if v.d > u.d + w(u, v)
7         return FALSE
8   return TRUE
*/

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>

class KnightMovesSolver {
private:
    int n;  // Tamanho do tabuleiro de xadrez (n x n)
    std::vector<std::vector<int>> board;  // Representação do tabuleiro

    // Função auxiliar para converter coordenadas (i, j) para um índice único em um array
    int index(int i, int j) {
        return i * n + j;
    }

public:
    KnightMovesSolver(int size) : n(size) {
        // Inicialização do tabuleiro
        board.resize(n, std::vector<int>(n, INT_MAX));
    }

    // Método para relaxar a aresta (u, v)
    void relax(int u, int v, std::vector<int>& dist) {
        if (dist[v] > dist[u] + 1) {
            dist[v] = dist[u] + 1;
        }
    }

    // Método para resolver o Problema do Cavaleiro Viajante
    bool findShortestDistance(std::pair<int, int> a, std::pair<int, int> b) {
        // Inicialização
        int inf = INT_MAX;
        int V = n * n;  // Número total de quadrados no tabuleiro
        std::vector<int> dist(V, inf);
        dist[index(a.first, a.second)] = 0;

        // Movimentos possíveis de um cavaleiro
        std::vector<std::pair<int, int>> moves = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
            {1, -2}, {1, 2}, {2, -1}, {2, 1}
        };

        // Relaxamento de arestas
        for (int i = 1; i <= V - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int u = index(j, k);
                    for (const auto& move : moves) {
                        int ni = j + move.first;
                        int nj = k + move.second;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            int v = index(ni, nj);
                            relax(u, v, dist);
                        }
                    }
                }
            }
        }

        // Verificação de ciclo negativo
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int u = index(i, j);
                for (const auto& move : moves) {
                    int ni = i + move.first;
                    int nj = j + move.second;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        int v = index(ni, nj);
                        if (dist[v] > dist[u] + 1) {
                            return false;
                        }
                    }
                }
            }
        }

        // Saída
        std::cout << "To get from " << char(a.first + 'a') << a.second + 1 << " to "
                  << char(b.first + 'a') << b.second + 1 << " takes " << dist[index(b.first, b.second)] << " knight moves." << std::endl;

        return true;
    }
};

int main() {
    int size = 8;  // Tamanho do tabuleiro de xadrez (8x8)
    KnightMovesSolver solver(size);

    std::string input;
    while (std::getline(std::cin, input)) {
        std::istringstream iss(input);
        char fromCol, toCol;
        int fromRow, toRow;
        iss >> fromCol >> fromRow >> toCol >> toRow;

        std::pair<int, int> a = {fromCol - 'a', fromRow - 1};
        std::pair<int, int> b = {toCol - 'a', toRow - 1};

        if (!solver.findShortestDistance(a, b)) {
            std::cout << "Negative cycle detected. The Bellman-Ford algorithm is not suitable for the TKP." << std::endl;
        }
    }

    return 0;
}
