//Douglas Leonel de Almeida
//Matricula - 2110213

#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int main() {
  int n, i, main_calls = 0, swaps = 0, comparisons = 0;

  // Recebe o tamanho do vetor
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  // Aloca o vetor dinamicamente
  int* vetor = (int*) malloc(n * sizeof(int));

  // Preenche o vetor com números aleatórios
  for(i = 0; i < n; i++) {
    vetor[i] = rand() % 1001;
  }

  // Imprime o vetor original
  printf("\nVetor Original:\n");
  for(i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }

  // Realiza a ordenação com MergeSort
  MergeSort(vetor, 0, n-1, &main_calls, &swaps, &comparisons);

  // Imprime o vetor ordenado e as informações sobre a ordenação
  printf("\n\nMergeSort:\n");
  printf("Vetor Ordenado:\n");
  for(i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\nNumero de chamadas a funcao principal: %d\n", main_calls);
  printf("Numero de Trocas: %d\n", swaps);
  printf("Numero de Comparacoes: %d\n", comparisons);

  // Realiza a ordenação com HeapSort
  HeapSort(vetor, n, &main_calls, &swaps, &comparisons);

  // Imprime o vetor ordenado e as informações sobre a ordenação
  printf("\nHeapSort:\n");
  printf("Vetor Ordenado:\n");
  for(i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\nNumero de chamadas a funcao principal: %d\n", main_calls);
  printf("Numero de Trocas: %d\n", swaps);
  printf("Numero de Comparacoes: %d\n", comparisons);

  // Libera a memória alocada para o vetor
  free(vetor);

  return 0;
}
