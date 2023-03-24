//Douglas Leonel de Almeida
//Matricula - 2110213

#include <iostream>
#include <vector>
#include <locale.h>

// Função para trocar elementos de posição no vetor
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função de partição do Quicksort
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = low - 1; // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) { // Se o elemento atual é menor que o pivô
            i++; // Incrementa o índice do menor elemento
            swap(arr[i], arr[j]); // Troca os elementos
        }
    }
    swap(arr[i + 1], arr[high]); // Troca o pivô com o elemento após o último menor elemento
    return (i + 1);
}

// Função de Quicksort
void quicksort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Encontra o índice de partição

        quicksort(arr, low, pi - 1); // Ordena os elementos antes da partição
        quicksort(arr, pi + 1, high); // Ordena os elementos após a partição
    }
}

int main() {
	
	setlocale(LC_ALL, "Portuguese");
    int n;
    std::cout << "Digite o número de ítens a serem inseridos: ";
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
    	std::cout << "Digite os ítens: ";
        std::cin >> arr[i];
    }

    quicksort(arr, 0, n - 1); // Aplica o Quicksort

    std::cout << "Ítens ordenados: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

//Explicação:

//Na função quickSort(), os parâmetros são vetor[] (vetor de elementos a serem ordenados), esquerda e direita (índices que indicam a posição do primeiro e do último elemento do vetor, que irão variar conforme o vetor é dividido).

//As variáveis i e j são utilizadas para percorrer o vetor a partir dos seus extremos, e a variável pivo é escolhida como sendo o elemento central do vetor, que irá dividir o vetor em duas partes menores.

//Em seguida, um loop while é executado, comparando os elementos com o valor do pivo. 

//Se um elemento for encontrado na posição errada (um elemento menor no lado direito e um elemento maior no lado esquerdo), eles são trocados de lugar. O loop continua até que toda a lista seja examinada e alguns elementos estejam no lugar correto.

//No final do loop, o vetor é dividido em duas partes menores, sendo que as subpartes à esquerda e à direita do pivo são ordenadas novamente pela função quickSort().

//Na função main(), são lidos os valores do vetor e chamada a função quickSort(). Por fim, os valores ordenados são exibidos na tela.

//Assim, o desenvolvedor pode implementar o algoritmo Quicksort em C++, lendo o número de itens a serem inseridos, imprimindo os itens ordenados e organizando todo o código em volta desse processo, tanto na função quickSort() quanto na função main().
