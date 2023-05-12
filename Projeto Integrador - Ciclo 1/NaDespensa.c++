//Douglas Leonel de Almeida
//Matricula - 2110213
//Projeto: NaDespensa
//Algoritomo de ordenação dos alimentos adicionados no software na despensa.
//Implementação do algoritmo Quicksort.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Fruta {
    std::string nome;
    int quantidade;
};

void swap(Fruta &a, Fruta &b) {
    Fruta temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<Fruta> &arr, int low, int high) {
    int pivot = arr[high].quantidade;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].quantidade < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(std::vector<Fruta> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    int n;
    std::cout << "Digite o número de alimentos a serem inseridas na sua despensa: ";
    std::cin >> n;

    std::vector<Fruta> frutas(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Digite o nome do alimento " << i+1 << ": ";
        std::cin >> frutas[i].nome;

        std::cout << "Digite a quantidade do alimento " << frutas[i].nome << ": ";
        std::cin >> frutas[i].quantidade;
    }

    quicksort(frutas, 0, n - 1);
    std::cout << "Despensa ordenada:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << frutas[i].nome << ": " << frutas[i].quantidade << std::endl;
    }

    return 0;
}
