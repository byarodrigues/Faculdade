//* Cadeia Alimentar: Ordenação topológica * //

/*
=While Bino was traveling, he drew some food chains of living organisms of Binox. However, Bino noted in some chains that all pairs of species relate (directly of indirectly). He called these chains as Cadeias Boladas.
=Representing the food chain as a graph, all pairs of species (u, v) relate if exist a path from u to v OR a path from v to u.
=From a food chain, Bino wants to know if it a Cadeia Bolada or Nao Cadeia Bolada.

=Input
=The input consists of multiple rows. The first row has two integers N (1 ≤ N ≤ 100000) and M (1 ≤ M ≤ 1000000), representing the amount of species and the number of relationships, respectively. The following M rows have two integers U (1 ≤ U ≤ N) and V (1 ≤ V ≤ N), representing the existence of an unidirectional relationship between U and V.

=Output
=Print out one row with the message “Bolada” (no quotes) if the chain is a Cadeia Bolada, or “Nao Bolada”, otherwise.

=1   call DFS(G) to compute finishing times v.f for each vertex v
=2   as each vertex is finished, insert it onto the front of a linked list
=3   return the linked list of vertices
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Grafo {
private:
    int V; // Número de vértices
    vector<list<int>> adj; // Lista de adjacência

public:
    Grafo(int vertices) : V(vertices), adj(vertices) {}

    // Adiciona uma aresta ao grafo
    void adicionarAresta(int u, int v) {
        adj[u].push_back(v);
    }

    // Utilitário DFS para verificar ciclos no grafo
    bool DFSUtil(int v, vector<bool>& visitado, vector<bool>& pilhaRecursiva) {
        visitado[v] = true;
        pilhaRecursiva[v] = true;

        for (const auto& u : adj[v]) {
            if (!visitado[u]) {
                if (DFSUtil(u, visitado, pilhaRecursiva)) {
                    return true; // Encontrou um ciclo
                }
            } else if (pilhaRecursiva[u]) {
                return true; // Encontrou um ciclo
            }
        }

        pilhaRecursiva[v] = false; // Remove o vértice da pilha recursiva
        return false;
    }

    // Verifica se há ciclos no grafo usando DFS
    bool temCiclo() {
        vector<bool> visitado(V, false);
        vector<bool> pilhaRecursiva(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visitado[i]) {
                if (DFSUtil(i, visitado, pilhaRecursiva)) {
                    return true; // Encontrou um ciclo
                }
            }
        }

        return false; // Não há ciclo
    }

    // Verifica se a cadeia é bolada usando a detecção de ciclo
    bool cadeiaBolada() {
        return temCiclo();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Grafo grafo(N);

    // Adiciona arestas ao grafo com base nos inputs
    for (int i = 0; i < M; ++i) {
        int U, V;
        cin >> U >> V;
        grafo.adicionarAresta(U - 1, V - 1);  // Ajustado para começar em 0
    }

    // Verifica se a cadeia é bolada e imprime o resultado
    if (grafo.cadeiaBolada()) {
        cout << "Bolada\n";
    } else {
        cout << "Nao Bolada\n";
    }

    return 0;
}
