//Douglas Leonel de Almeida
//Matricula - 2110213

#include <iostream>
#include <vector>

using namespace std;

int buscaSequencial(const vector<int>& vetor, int elemento) {
    int comp = 0;
    for (int i = 0; i < vetor.size(); i++) {
        comp++;
        if (vetor[i] == elemento) {
            cout << "Número de comparações (busca sequencial): " << comp << endl;
            return i;
        }
    }
    cout << "Elemento não encontrado." << endl;
    return -1;
}

int buscaBinaria(const vector<int>& vetor, int elemento) {
    int comp = 0;
    int esquerda = 0, direita = vetor.size() - 1;
    while (esquerda <= direita) {
        comp++;
        int meio = (esquerda + direita) / 2;
        if (vetor[meio] == elemento) {
            cout << "Número de comparações (busca binária): " << comp << endl;
            return meio;
        } else if (vetor[meio] < elemento) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    cout << "Elemento não encontrado." << endl;
    return -1;
}

int main() {
    vector<int> vetor = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 17, 22, 35, 39, 41, 44, 47, 48, 49, 51, 55, 64, 67, 87, 89, 99, 100};
    int elemento = 48;
    int indexSequencial = buscaSequencial(vetor, elemento);
    int indexBinaria = buscaBinaria(vetor, elemento);
    return 0;
}
