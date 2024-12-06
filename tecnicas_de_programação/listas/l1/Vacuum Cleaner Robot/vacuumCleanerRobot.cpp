//* Robô Aspirador: Busca em largura*//
/*
Ricciardi, the vacuum cleaner robot, received orders. It must clean the maximum possible number of the N dusts on the ground and reach the recharge station. It seems to be a trivial task. However, Ricciardi’s battery is damaged, and it can make only M moves before it exhausts.
The robot is located in a rectangular room with W × H square cells. In one move, it can go to the cell directly above, below, to the left or to the right of its current cell, but only if it does not contain any obstacle. Determined to save energy while finishing its job, Ricciardi asked you to write a program that calculates the maximum number of dusts it can clean.

Input
The input contains several test cases. The first line of each test case contains two integers N (1 ≤ N ≤ 8) and M (1 ≤ M ≤ 109). The second line contains two integers W and H (5 ≤ W, H ≤ 100).
The following H lines contains W characters each, describing the room. Obstacles are represented by '#', empty cells by '.' , Ricciardi’s initial cell by 'R', dusts by '*' and the recharge station by 'S'.
Riccardi automatically cleans a dust when passing by it. It can also pass over the recharge station, the same way it can pass over any empty cell.
The input ends with end-of-file (EOF).

Output
For each test case, print a single line with one integer only, the maximum number of dusts the robot can collect before going to the recharge station. If the robot cannot reach the station, print -1.

BFS(G, s)
 1   for each vertex u ϵ G.V - {s}
 2      u.color = WHITE
 3      u.d = ∞
 4      u.π = NIL
 5   s.color = GRAY
 6   s.d = 0
 7   s.π = NIL
 8   Q = Ø
 9   ENQUEUE(Q, s)
10   while Q ≠ Ø
11      u = DEQUEUE(Q)
12      for each v ϵ G.Adj[u]
13         if v.color == WHITE
14            v.color = GRAY
15            v.d = u.d + 1
16            v.π = u
17            ENQUEUE(Q, v)
18      u.color = BLACK
*/

#include <iostream>
#include <vector>
#include <queue>

// Estrutura para representar um ponto (coordenadas x, y)
struct Ponto {
    int x, y;
};

class RoboAspirador {
public:
    // Construtor da classe RoboAspirador
    RoboAspirador(int largura, int altura, int maxMovimentos);

    // Métodos para adicionar elementos à sala
    void adicionarObstaculo(int x, int y);
    void adicionarDust(int x, int y);
    void adicionarRechargeStation(int x, int y);
    void adicionarPosicaoInicial(int x, int y);

    // Método para encontrar o caminho mais eficiente
    int encontrarCaminho();

private:
    // Representação da sala como uma matriz de caracteres
    std::vector<std::vector<char>> sala;

    // Matriz para controlar os locais já visitados
    std::vector<std::vector<bool>> visitado;

    // Número máximo de movimentos permitidos
    int maxMovimentos;

    // Coordenadas do ponto inicial e da estação de recarga
    Ponto posicaoInicial, estacaoRecarga;

    // Função para verificar se é possível mover para uma determinada posição
    bool podeMover(int x, int y);
};

// Implementação dos métodos da classe RoboAspirador

// Construtor da classe RoboAspirador
RoboAspirador::RoboAspirador(int largura, int altura, int maxMovimentos)
    : sala(altura, std::vector<char>(largura, '.')), visitado(altura, std::vector<bool>(largura, false)), maxMovimentos(maxMovimentos) {}

// Adiciona um obstáculo à sala
void RoboAspirador::adicionarObstaculo(int x, int y) {
    sala[y][x] = '#';
}

// Adiciona um monte de poeira à sala
void RoboAspirador::adicionarDust(int x, int y) {
    sala[y][x] = '*';
}

// Adiciona a estação de recarga à sala
void RoboAspirador::adicionarRechargeStation(int x, int y) {
    sala[y][x] = 'S';
    estacaoRecarga = {x, y};
}

// Adiciona a posição inicial do robô à sala
void RoboAspirador::adicionarPosicaoInicial(int x, int y) {
    sala[y][x] = 'R';
    posicaoInicial = {x, y};
}

// Verifica se é possível mover para uma determinada posição
bool RoboAspirador::podeMover(int x, int y) {
    return x >= 0 && x < sala[0].size() && y >= 0 && y < sala.size() && sala[y][x] != '#' && !visitado[y][x];
}

// Encontra o caminho mais eficiente usando Busca em Largura (BFS)
int RoboAspirador::encontrarCaminho() {
    // Fila para armazenar os pontos e o número de movimentos
    std::queue<std::pair<Ponto, int>> fila;
    fila.push({posicaoInicial, 0});

    // Loop principal da BFS
    while (!fila.empty()) {
        Ponto ponto = fila.front().first;
        int movimentosRestantes = fila.front().second;
        fila.pop();

        int x = ponto.x;
        int y = ponto.y;

        // Verifica se é possível mover para a posição atual
        if (podeMover(x, y)) {
            visitado[y][x] = true;

            // Se encontrou a estação de recarga
            if (ponto.x == estacaoRecarga.x && ponto.y == estacaoRecarga.y) {
                return movimentosRestantes;
            }

            // Adiciona vizinhos válidos
            if (podeMover(x + 1, y)) fila.push({{x + 1, y}, movimentosRestantes + 1});
            if (podeMover(x - 1, y)) fila.push({{x - 1, y}, movimentosRestantes + 1});
            if (podeMover(x, y + 1)) fila.push({{x, y + 1}, movimentosRestantes + 1});
            if (podeMover(x, y - 1)) fila.push({{x, y - 1}, movimentosRestantes + 1});
        }
    }

    // Se não encontrou caminho até a estação de recarga
    return -1;
}

// Função principal
int main() {
    int N, M, W, H;

    // Loop para processar vários casos de teste
    while (std::cin >> N >> M >> W >> H) {
        // Cria uma instância do RoboAspirador
        RoboAspirador robo(W, H, M);

        // Preenche a sala com as informações do caso de teste
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                char c;
                std::cin >> c;

                if (c == '#') {
                    robo.adicionarObstaculo(j, i);
                } else if (c == '*') {
                    robo.adicionarDust(j, i);
                } else if (c == 'S') {
                    robo.adicionarRechargeStation(j, i);
                } else if (c == 'R') {
                    robo.adicionarPosicaoInicial(j, i);
                }
            }
        }

        // Encontra o caminho mais eficiente e obtém o número de movimentos restantes
        int movimentosRestantes = robo.encontrarCaminho();

        // Verifica se o robô não conseguiu chegar à estação de recarga
        if (movimentosRestantes == -1 || movimentosRestantes > M) {
            std::cout << -1 << std::endl;
        } else {
            // Calcula o número de poeiras coletadas (garante que nunca seja negativo)
            std::cout << std::max(0, N - (M - movimentosRestantes)) << std::endl;
        }

    }

    return 0;
}
