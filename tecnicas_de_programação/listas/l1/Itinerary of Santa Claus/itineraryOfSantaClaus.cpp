//* Itinerário do Papai Noel: Kruskal * //

/*
Before Santa Claus begin his travels in Brazil to deliver Christmas presents, he asked you to help him drawing a map with all the cities that he should visit. Follows the rule to draw this map: the sum of all routes (distances between two cities) existing on the map should be as small as possible and must be possible to arrive in any destination from any origin. Claus does not mind to go to a particular city more than once, as long as it uses only the routes drawn on the map.

Input
The input file contains several test cases. Each test case starts with two numbers M (2 ≤ M < 40000) and N (1 ≤ N < 50000), the number of cities and the number of roads respectively. Input is terminated by M = N = 0. Then follow N integer triples X (0 ≤ X), Y (Y < M) and Z (1 ≤ Z ≤ 999), pecifying that there will be a bidirectional route between X and Y with Z kilometers, considering that X ≠ Y and the total sum of all routes in each map is less than 231.

Output
For each test case, print a single integer indicating the sum of all distances or routes of your map.

MST-KRUSKAL(G, w)
1   A = Ø
2   for each vertex v ϵ G.V
3      MAKE-SET(v)
4   sort the edges of G.E into nondecreasing order by weight w
5   for each edge (u, v) ϵ G.E, taken in nondecreasing order by weight
6      if FIND-SET(u) ≠ FIND-SET(v)
7         A = A U {(u, v)}
8         UNION(u, v)
9   return A
*/

#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet {
public:
    // Construtor da classe DisjointSet
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Função para encontrar o conjunto (com otimização de caminho)
    int findSet(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = findSet(parent[v]);
    }

    // Função para unir dois conjuntos (com união por rank)
    void unionSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if (a != b) {
            if (rank[a] < rank[b]) {
                std::swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

struct City {
    int id;

    // Construtor da classe City
    City(int id) : id(id) {}

    // Sobrecarga do operador de igualdade para comparar cidades
    bool operator==(const City& other) const {
        return id == other.id;
    }
};

struct Route {
    City origin, destination;
    int distance;

    // Construtor da classe Route
    Route(const City& origin, const City& destination, int distance)
        : origin(origin), destination(destination), distance(distance) {}
};

class Graph {
public:
    // Adiciona uma cidade ao grafo
    void addCity(const City& city) {
        cities.push_back(city);
    }

    // Adiciona uma rota ao grafo
    void addRoute(const City& origin, const City& destination, int distance) {
        routes.push_back(Route(origin, destination, distance));
    }

    // Executa o algoritmo de Kruskal para encontrar a MST e retorna a soma das distâncias
    int kruskalMST() {
        // Ordena as rotas por distância
        std::sort(routes.begin(), routes.end(), [](const Route& a, const Route& b) {
            return a.distance < b.distance;
        });

        DisjointSet ds(cities.size());
        int totalDistance = 0;

        // Itera sobre as rotas e forma a MST
        for (const Route& route : routes) {
            int originIndex = getIndex(route.origin);
            int destinationIndex = getIndex(route.destination);

            // Verifica se a adição da aresta forma um ciclo
            if (ds.findSet(originIndex) != ds.findSet(destinationIndex)) {
                totalDistance += route.distance;
                ds.unionSets(originIndex, destinationIndex);
            }
        }

        return totalDistance;
    }

private:
    std::vector<City> cities;
    std::vector<Route> routes;

    // Obtém o índice de uma cidade no vetor de cidades
    int getIndex(const City& city) {
        auto it = std::find(cities.begin(), cities.end(), city);
        return std::distance(cities.begin(), it);
    }
};

int main() {
    while (true) {
        int M, N;
        std::cin >> M >> N;

        if (M == 0 && N == 0) {
            break; // Fim do input
        }

        Graph g;

        // Adiciona cidades ao grafo
        for (int i = 0; i < M; ++i) {
            g.addCity(City(i));
        }

        // Adiciona rotas ao grafo
        for (int i = 0; i < N; ++i) {
            int X, Y, Z;
            std::cin >> X >> Y >> Z;
            g.addRoute(City(X), City(Y), Z);
        }

        // Calcula a soma das distâncias para a MST e imprime
        int totalDistance = g.kruskalMST();
        std::cout << totalDistance << std::endl;
    }

    return 0;
}
