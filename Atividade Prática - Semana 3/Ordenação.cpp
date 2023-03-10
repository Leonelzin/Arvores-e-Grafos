//Douglas Leonel de Almeida
//Matricula - 2110213

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ordenacao.h>


void gera_vetor(int tamanho, int *vetor) {
    int i;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1001;
    }
}

void bubble_sort(int tamanho, int *vetor, int *num_trocas, int *num_comparacoes) {
    int i, j, aux, trocou;

    *num_trocas = 0;
    *num_comparacoes = 0;

    for (i = 0; i < tamanho - 1; i++) {
        trocou = 0;

        for (j = 0; j < tamanho - 1 - i; j++) {
            (*num_comparacoes)++;

            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                (*num_trocas)++;
                trocou = 1;
            }
        }

        if (!trocou) {
            break;
        }
    }
}

void select_sort(int tamanho, int *vetor, int *num_trocas, int *num_comparacoes) {
    int i, j, min, aux;

    *num_trocas = 0;
    *num_comparacoes = 0;

    for (i = 0; i < tamanho - 1; i++) {
        min = i;

        for (j = i + 1; j < tamanho; j++) {
            (*num_comparacoes)++;

            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }

        if (i != min) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
            (*num_trocas)++;
        }
    }
}

void insertion_sort(int tamanho, int *vetor, int *num_trocas, int *num_comparacoes) {
    int i, j, atual;

    *num_trocas = 0;
    *num_comparacoes = 0;

    for (i = 1; i < tamanho; i++) {
        atual = vetor[i];

        for (j = i - 1; j >= 0 && vetor[j] > atual; j--) {
            (*num_comparacoes)++;
            vetor[j + 1] = vetor[j];
            (*num_trocas)++;
        }

        vetor[j + 1] = atual;
    }
}
