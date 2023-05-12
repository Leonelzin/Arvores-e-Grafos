//Douglas Leonel de Almeida
//Matricula - 2110213
//Projeto: NaDespensa
//Funções de busca sequencial e binária implementadas:

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

int sequential_search(std::vector<Fruta> &arr, std::string nome) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].nome == nome) {
            return i;
        }
    }
    return -1;
}

int binary_search(std::vector<Fruta> &arr, std::string nome) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].nome == nome) {
            return mid;
        }
        else if (arr[mid].nome < nome) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
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

    std::string nome_busca;
    std::cout << "Digite o nome do alimento que deseja buscar: ";
    std::cin >> nome_busca;

    int index_sequential = sequential_search(frutas, nome_busca);
    if (index_sequential == -1) {
        std::cout << "Alimento não encontrado (busca sequencial)" << std::endl;
    }
    else {
        std::cout << "Alimento encontrado na posição " << index_sequential << " (busca sequencial)" << std::endl;
    }

    int index_binary = binary_search(frutas, nome_busca);
    if (index_binary == -1) {
        std::cout << "Alimento não encontrado (busca binária)" << std::endl;
    }
    else {
        std::cout << "Alimento encontrado na posição " << index_binary << " (busca binária)" << std::endl;
    }

    return 0;
}
