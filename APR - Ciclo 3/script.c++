//Douglas Leonel de Almeida
//Matricula - 2110213

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Adjacente {
    int vertice;
    int distancia;
};

struct Vertice {
    int id;
    vector<Adjacente> adjacencias;
};

class Grafo {
private:
    vector<Vertice> vertices;

public:
    void adicionarVertice(int id) {
        Vertice v;
        v.id = id;
        vertices.push_back(v);
    }

    void adicionarAresta(int origem, int destino, int distancia) {
        Adjacente adj;
        adj.vertice = destino;
        adj.distancia = distancia;

        vertices[origem].adjacencias.push_back(adj);
    }

    vector<int> calcularDistanciaMinima(int origem) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
        vector<int> distancia(vertices.size(), numeric_limits<int>::max());

        fila.push(make_pair(0, origem));
        distancia[origem] = 0;

        while (!fila.empty()) {
            int u = fila.top().second;
            fila.pop();

            for (const Adjacente& adj : vertices[u].adjacencias) {
                int v = adj.vertice;
                int peso = adj.distancia;

                if (distancia[u] + peso < distancia[v]) {
                    distancia[v] = distancia[u] + peso;
                    fila.push(make_pair(distancia[v], v));
                }
            }
        }

        return distancia;
    }
};

int main() {
    Grafo grafo;

    // Adicione as unidades de saúde como vértices do grafo
    grafo.adicionarVertice(0);  // US1
    grafo.adicionarVertice(1);  // US2
    grafo.adicionarVertice(2);  // US3
    grafo.adicionarVertice(3);  // US4
    grafo.adicionarVertice(4);  // US5

    // Adicione as distâncias entre as unidades de saúde como arestas do grafo
    grafo.adicionarAresta(0, 1, 10);  // US1 -> US2 (distância: 10)
    grafo.adicionarAresta(0, 2, 5);   // US1 -> US3 (distância: 5)
    grafo.adicionarAresta(1, 2, 2);   // US2 -> US3 (distância: 2)
    grafo.adicionarAresta(1, 3, 8);   // US2 -> US4 (distância: 8)

    int origem = 0;  // Unidade de saúde de origem para calcular a distância mínima

    vector<int> distancia = grafo.calcularDistanciaMinima(origem);

    // Imprime a distância mínima de cada unidade de saúde em relação à origem
    cout << "Distância mínima da Unidade de Saúde " << origem << ":\n";
    for (int i = 0; i < distancia.size(); ++i) {
        cout << "US" << i << ": " << distancia[i] << " km\n";
    }

    return 0;
}
