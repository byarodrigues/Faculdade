//* Credo com ParaTudo!: Floyd-Warshall *//

/*
Harari was a very intelligent young man who loved to eat and drink. One day, she went out with her friends, and after a night of lots of laughs and good drinks, she got the idea of ​​buying a very good ginger yogurt that was in fashion right now called ParaTudo. When taking it with his friends, he noticed that the yogurt really stopped his entire digestive system and everyone panicked needing to go each to their respective home. Due to the good drinks they took, the friends were lost in the city, and were afraid of not being able to get to their homes, especially since many streets were closed because of the upcoming Carnival. Given the number of neighborhoods in the city and their connections (all of these connections being possible to be crossed by both directions), answer the various questions of Harari and his friends, where each question should answer if, from neighborhood A, it is possible to reach a neighborhood B by the available connections.

Input
The first line of the entry contains three integers N (0 < N ≤ 400), M (0 ≤ M ≤ (( N -1)* N ))/2) and P (0 ≤ P ≤ 105), indicating respectively the number of neighborhoods, the number of connections in the city of Harari and how many questions were asked. The next M lines describe the connections, where each line has 2 integers, A and B (0 < A , B ≤ N) indicating that such a connection connects these two neighborhoods. The next P lines describe the questions asked, where in each row there will be two integers, K and L, asking whether or not it is possible to go from K to L for the available connections.

Output
For each question, there should be one of the following answers:
"Lets que lets", if it is possible to get from one neighborhood to another;
"Deu ruim", if it is not possible to get from one neighborhood to another.

FLOYD-WARSHALL(W)
1   n = W.rows
2   D(0)
 = W
3   for k = 1 to n
4      let D(k)=(d(k)ij)
 be a new n x n matrix
5      for i = 1 to n
6         for j = 1 to n
7         d(k)ij=min(d(k−1)ij,d(k−1)ik+d(k−1)kj)

8   return D(n)
*/

#include <iostream>
#include <vector>
#include <climits>

class ConnectivityChecker {
private:
    int numNeighborhoods;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    ConnectivityChecker(int numNeighborhoods, const std::vector<std::pair<int, int>>& connections) {
        this->numNeighborhoods = numNeighborhoods;

        // Inicializando a matriz de adjacência
        adjacencyMatrix.resize(numNeighborhoods, std::vector<int>(numNeighborhoods, INT_MAX));

        // Inicializando a diagonal principal com 0
        for (int i = 0; i < numNeighborhoods; ++i) {
            adjacencyMatrix[i][i] = 0;
        }

        // Preenchendo a matriz de adjacência com as conexões fornecidas
        for (const auto& connection : connections) {
            int neighborhoodA = connection.first - 1;  // Ajustando para índices baseados em zero
            int neighborhoodB = connection.second - 1;

            adjacencyMatrix[neighborhoodA][neighborhoodB] = 1;
            adjacencyMatrix[neighborhoodB][neighborhoodA] = 1;  // Assumindo que as conexões são bidirecionais
        }
    }

    void runFloydWarshall() {
        for (int k = 0; k < numNeighborhoods; ++k) {
            for (int i = 0; i < numNeighborhoods; ++i) {
                for (int j = 0; j < numNeighborhoods; ++j) {
                    if (adjacencyMatrix[i][k] != INT_MAX && adjacencyMatrix[k][j] != INT_MAX
                        && adjacencyMatrix[i][k] + adjacencyMatrix[k][j] < adjacencyMatrix[i][j]) {
                        adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                    }
                }
            }
        }
    }

    bool isReachable(int from, int to) const {
        return adjacencyMatrix[from][to] != INT_MAX;
    }
};

int main() {
    // Leitura de entrada
    int numNeighborhoods, numConnections, numQuestions;
    std::cin >> numNeighborhoods >> numConnections >> numQuestions;

    std::vector<std::pair<int, int>> connections;
    for (int i = 0; i < numConnections; ++i) {
        int neighborhoodA, neighborhoodB;
        std::cin >> neighborhoodA >> neighborhoodB;
        connections.emplace_back(neighborhoodA, neighborhoodB);
    }

    // Criando instância da classe ConnectivityChecker
    ConnectivityChecker checker(numNeighborhoods, connections);
    checker.runFloydWarshall();

    // Respondendo às perguntas
    for (int i = 0; i < numQuestions; ++i) {
        int from, to;
        std::cin >> from >> to;

        if (checker.isReachable(from - 1, to - 1)) {
            std::cout << "Lets que lets" << std::endl;
        } else {
            std::cout << "Deu ruim" << std::endl;
        }
    }

    return 0;
}
