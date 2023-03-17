//Douglas Leonel de Almeida
//Matricula - 2110213

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *arr, int low, int high, int *calls, int *swaps, int *comps);
int partition(int *arr, int low, int high, int *swaps, int *comps);
void swap(int *a, int *b);

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1001;
    }

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int calls = 0, swaps = 0, comps = 0;
    quicksort(arr, 0, n - 1, &calls, &swaps, &comps);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Chamadas recursivas: %d\n", calls);
    printf("Trocas realizadas: %d\n", swaps);
    printf("Comparacoes realizadas: %d\n", comps);

    return 0;
}

void quicksort(int *arr, int low, int high, int *calls, int *swaps, int *comps) {
    (*calls)++;
    if (low < high) {
        int pivot = partition(arr, low, high, swaps, comps);
        quicksort(arr, low, pivot - 1, calls, swaps, comps);
        quicksort(arr, pivot + 1, high, calls, swaps, comps);
    }
}

int partition(int *arr, int low, int high, int *swaps, int *comps) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        (*comps)++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            (*swaps)++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*swaps)++;
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
