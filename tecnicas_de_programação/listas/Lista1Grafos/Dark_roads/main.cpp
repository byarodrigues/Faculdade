#include <iostream>
/*
Kruskal
Os tempos econômicos atualmente são difíceis,
mesmo em Byteland. Para reduzir os custos
operacionais, o governo de Byteland decidiu
otimizar a iluminação da estrada. Até agora
todas as estradas foram iluminadas durante
toda a noite, o que custa 1 dólar bytelandiano
por metro e dia. Para economizar dinheiro,
eles decidiram não mais iluminar todas as
estradas, mas desligar a iluminação de algumas
ruas. Para garantir que os habitantes de
Byteland ainda se sintam seguros, eles querem
otimizar a iluminação de forma que, depois de
escurecer algumas ruas à noite, ainda haja
pelo menos um caminho iluminado de cada
cruzamento em Byteland para todos os outros
cruzamentos.

Qual é a quantia máxima diária de dinheiro que
o governo de Byteland pode economizar, sem
fazer com que seus habitantes se sintam
inseguros?
Entrada
O arquivo de entrada contém vários casos de
teste. Cada caso de teste começa com dois
números m (1 ≤ m ≤ 200000) en ( m -1 ≤ n ≤
200000), que são o número de cruzamentos em
Byteland e o número de estradas em Byteland,
respectivamente. Siga n inteiros triplos x ,
y , z , especificando que haverá uma estrada
bidirecional entre x e y com comprimento z
metros (0 ≤ x , y < m e x ≠ y ).

A entrada é terminada por m = n =0. O grafo
especificado por cada caso de teste é
conectado. O comprimento total de todas as
estradas em cada caso de teste é inferior a
2 31 .

Saída
Para cada caso de teste, imprima uma linha
contendo o valor diário máximo que o governo
pode economizar.


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int u, v, w;
};

class Graph {
 public:
  Graph(int n) {
    adj.resize(n);
  }

  void add_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<vector<int>> dijkstra(int s) {
    vector<int> dist(adj.size(), INT_MAX);
    dist[s] = 0;
    vector<bool> visited(adj.size(), false);

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      visited[u] = true;

      for (auto& e : adj[u]) {
        int v = e.u;
        int w = e.w;

        if (!visited[v] && dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          q.push(v);
        }
      }
    }

    return {dist};
  }

 private:
  vector<vector<Edge>> adj;
};

int min_cost_to_turn_off_lights(int n, int m, vector<Edge>& roads) {
  // Construa o grafo.
  Graph graph(n);
  for (auto& e : roads) {
    graph.add_edge(e.u, e.v, e.w);
  }

  // Encontre o caminho mais curto entre todos os pares de cruzamentos.
  auto distances = graph.dijkstra(0);

  // Calcule o custo de desligar a iluminação de cada estrada.
  vector<int> costs;
  for (auto& e : roads) {
    costs.push_back(e.w * distances[e.u][e.v]);
  }

  // Encontre o conjunto de estradas que minimiza o custo total.
  vector<int> dp(1 << m);
  for (int subset = 1; subset < (1 << m); subset++) {
    for (int road = 0; road < m; road++) {
      if ((subset >> road) & 1) {
        dp[subset] = min(dp[subset], dp[subset ^ (1 << road)] + costs[road]);
      }
    }
  }
  return dp.back();
}

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) {
      break;
    }

    vector<Edge> roads(m);
    for (int i = 0; i < m; i++) {
      cin >> roads[i].u >> roads[i].v >> roads[i].w;
    }

    cout << min_cost_to_turn_off_lights(n, m, roads) << endl;
  }
  return 0;
}
