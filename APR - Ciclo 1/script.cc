//Douglas Leonel de Almeida
//Matricula - 2110213

#include <iostream>
#include <vector>

using namespace std;

//Função para imprimir um vetor
void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

//Função para ordenar um vetor utilizando o algoritmo QuickSort
void quickSort(vector<int> &v, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = v[inicio];
        int i = inicio + 1, j = fim;

        while (i <= j) {
            if (v[i] <= pivo) {
                i++;
            } else if (v[j] > pivo) {
                j--;
            } else {
                swap(v[i], v[j]);
            }
        }

        swap(v[inicio], v[j]);

        quickSort(v, inicio, j - 1);
        quickSort(v, j + 1, fim);
    }
}

//Função para ordenar um vetor utilizando o algoritmo Bubble Sort
void bubbleSort(vector<int> &v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

//Função para ordenar um vetor utilizando o algoritmo Selection Sort
void selectionSort(vector<int> &v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        swap(v[i], v[minIndex]);
    }
}

//Função para ordenar um vetor utilizando o algoritmo Insertion Sort
void insertionSort(vector<int> &v) {
    int n = v.size();

    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

//Função principal para teste
int main() {
    std::vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(8);
	v.push_back(1);
	v.push_back(2);
	v.push_back(7);
	v.push_back(4);
	v.push_back(6);

    //Ordenação utilizando o algoritmo QuickSort
    quickSort(v, 0, v.size() - 1);
    printVector(v);

    //Ordenação utilizando o algoritmo Bubble Sort
    bubbleSort(v);
    printVector(v);

    //Ordenação utilizando o algoritmo Selection Sort
    selectionSort(v);
    printVector(v);

    //Ordenação utilizando o algoritmo Insertion Sort
    insertionSort(v);
    printVector(v);

    return 0;
}
