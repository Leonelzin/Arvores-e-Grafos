//Douglas Leonel de Almeida
//Matricula - 2110213

#include <iostream>
#include <vector>

using namespace std;

// Definição de uma classe para representar um grafo
class Grafo {
private:
    int numVertices;
    vector<vector<int>> adjacencia;

public:
    Grafo(int numVertices) {
        this->numVertices = numVertices;
        adjacencia.resize(numVertices);
    }

    void adicionarAresta(int origem, int destino) {
        adjacencia[origem].push_back(destino);
        adjacencia[destino].push_back(origem);
    }

    void imprimirGrafo() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Nó " << i << ": ";
            for (int j : adjacencia[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Grafo com 3 nós, cada um com grau 2
    Grafo grafo1(3);
    grafo1.adicionarAresta(0, 1);
    grafo1.adicionarAresta(0, 2);
    grafo1.adicionarAresta(1, 2);
    grafo1.imprimirGrafo();

    cout << endl;

    // Grafo com 4 nós e ciclos de comprimento 1, 2, 3 e 4
    Grafo grafo2(4);
    grafo2.adicionarAresta(0, 0); // Ciclo de comprimento 1
    grafo2.adicionarAresta(1, 2);
    grafo2.adicionarAresta(2, 3);
    grafo2.adicionarAresta(3, 1);
    grafo2.imprimirGrafo();

    cout << endl;

    // Grafo não completo com 4 nós, cada um com grau 4
    Grafo grafo3(4);
    grafo3.adicionarAresta(0, 1);
    grafo3.adicionarAresta(0, 2);
    grafo3.adicionarAresta(0, 3);
    grafo3.adicionarAresta(1, 2);
    grafo3.adicionarAresta(1, 3);
    grafo3.adicionarAresta(2, 3);
    grafo3.imprimirGrafo();

    return 0;
}
