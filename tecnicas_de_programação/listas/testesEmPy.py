import heapq

INFINITO = 1000000000

def dijkstra(grafo, origem):
    num_vertices = len(grafo)
    distancias = [INFINITO] * num_vertices
    distancias[origem] = 0

    heap = [(0, origem)]

    visitado = [False] * num_vertices

    while heap:
        distancia, u = heapq.heappop(heap)

        if visitado[u]:
            continue

        visitado[u] = True

        for vizinho, peso in grafo[u]:
            custo = distancias[u] + peso
            if custo < distancias[vizinho]:
                distancias[vizinho] = custo
                heapq.heappush(heap, (distancias[vizinho], vizinho))

    return distancias

def main():
    num_vertices = int(input())
    num_arestas = int(input())

    grafo = [[] for _ in range(num_vertices)]

    for _ in range(num_arestas):
        u, v, peso = map(int, input().split())
        u -= 1
        v -= 1
        grafo[u].append((v, peso))

    for i in range(num_vertices):
        print(f'vertice {i + 1}: {[(x[0] + 1, x[1]) for x in grafo[i]]}')

    distancias = dijkstra(grafo, 0)

    for i, distancia in enumerate(distancias):
        print(f'd[{i + 1}]: {distancia}')

if __name__ == "__main__":
    main()
