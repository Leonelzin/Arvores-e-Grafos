//Douglas Leonel de Almeida
//Matricula - 2110213

#include <stdio.h>
#include <stdlib.h>
#include <ordenacao.h>

int main() {
    int tamanho, opcao, i, num_trocas_bubble, num_comparacoes_bubble, num_trocas_select, num_comparacoes_select, num_trocas_insertion, num_comparacoes_insertion;
    int *vetor_original, *vetor_ordenado_bubble, *vetor_ordenado_select, *vetor_ordenado_insertion;

    printf("Digite o tamanho do vetor: ");

int main() {
    int tamanho, opcao, i, num_trocas_bubble, num_comparacoes_bubble, num_trocas_select, num_comparacoes_select, num_trocas_insertion, num_comparacoes_insertion, menor_num_trocas, menor_num_comparacoes, metodo_menor_num_trocas, metodo_menor_num_comparacoes;
    int *vetor_original, *vetor_ordenado_bubble, *vetor_ordenado_select, *vetor_ordenado_insertion;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor_original = (int*) malloc(tamanho * sizeof(int));
    vetor_ordenado_bubble = (int*) malloc(tamanho * sizeof(int));
    vetor_ordenado_select = (int*) malloc(tamanho * sizeof(int));
    vetor_ordenado_insertion = (int*) malloc(tamanho * sizeof(int));

    gera_vetor(tamanho, vetor_original);

    do {
        printf("\nMENU DE OPCOES\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Select Sort\n");
        printf("3 - Insertion Sort\n");
        printf("4 - Comparacao\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                for (i = 0; i < tamanho; i++) {
                    vetor_ordenado_bubble[i] = vetor_original[i];
                }

                bubble_sort(tamanho, vetor_ordenado_bubble, &num_trocas_bubble, &num_comparacoes_bubble);

                printf("\nVetor original: ");
                for (i = 0; i < tamanho; i++) {
                    printf("%d ", vetor_original[i]);
                }

                printf("\nVetor ordenado: ");
                for (i = 0; i < tamanho; i++) {
                    printf("%d ", vetor_ordenado_bubble[i]);
                }

                printf("\nNumero de trocas realizadas: %d", num_trocas_bubble);
                printf("\nQuantidade de comparacoes do metodo: %d\n", num_comparacoes_bubble);
                break;

            case 2:
                for (i = 0; i < tamanho; i++) {
                    vetor_ordenado_select[i] = vetor_original[i];
                }

                select_sort(tamanho, vetor_ordenado_select, &num_trocas_select, &num_comparacoes_select);

                printf("\nVetor original: ");
                for (i = 0; i < tamanho; i++) {
                    printf("%d ", vetor_original[i]);
                }

                printf("\nVetor ordenado: ");
                for (i = 0; i < tamanho; i++) {
                    printf("%d ", vetor_ordenado_select[i]);
                }

                printf("\nNumero de trocas realizadas: %d", num_trocas_select);
                printf("\nQuantidade de comparacoes do metodo: %d\n", num_comparacoes_select);
                break;

            case 3:
                for (i = 0; i < tamanho; i++) {
                    vetor_ordenado_insertion[i] = vetor_original[i];
                }

                insertion_sort(tamanho, vetor_ordenado_insertion,
            printf("\nVetor original: ");
            for (i = 0; i < tamanho; i++) {
                printf("%d ", vetor_original[i]);
            }

            printf("\nVetor ordenado: ");
            for (i = 0; i < tamanho; i++) {
                printf("%d ", vetor_ordenado_insertion[i]);
            }

            printf("\nNumero de trocas realizadas: %d", num_trocas_insertion);
            printf("\nQuantidade de comparacoes do metodo: %d\n", num_comparacoes_insertion);
            break;

        case 4:
            bubble_sort(tamanho, vetor_original, &num_trocas_bubble, &num_comparacoes_bubble);
            select_sort(tamanho, vetor_original, &num_trocas_select, &num_comparacoes_select);
            insertion_sort(tamanho, vetor_original, &num_trocas_insertion, &num_comparacoes_insertion);

            menor_num_trocas = num_trocas_bubble;
            metodo_menor_num_trocas = 1;

            if (num_trocas_select < menor_num_trocas) {
                menor_num_trocas = num_trocas_select;
                metodo_menor_num_trocas = 2;
            }

            if (num_trocas_insertion < menor_num_trocas) {
                menor_num_trocas = num_trocas_insertion;
                metodo_menor_num_trocas = 3;
            }

            menor_num_comparacoes = num_comparacoes_bubble;
            metodo_menor_num_comparacoes = 1;

            if (num_comparacoes_select < menor_num_comparacoes) {
                menor_num_comparacoes = num_comparacoes_select;
                metodo_menor_num_comparacoes = 2;
            }

            if (num_comparacoes_insertion < menor_num_comparacoes) {
                menor_num_comparacoes = num_comparacoes_insertion;
                metodo_menor_num_comparacoes = 3;
            }

            printf("\nComparacao de metodos de ordenacao:\n");
            printf("Metodo com menor numero de trocas: ");

            switch (metodo_menor_num_trocas) {
                case 1:
                    printf("Bubble Sort");
                    break;
                case 2:
                    printf("Select Sort");
                    break;
                case 3:
                    printf("Insertion Sort");
                    break;
            }

            printf("\nNumero de trocas realizadas: %d\n", menor_num_trocas);

            printf("Metodo com menor quantidade de comparacoes: ");

            switch (metodo_menor_num_comparacoes) {
                case 1:
                    printf("Bubble Sort");
                    break;
                case 2:
                    printf("Select Sort");
                    break;
                case 3:
                    printf("Insertion Sort");
                    break;
            }

            printf("\nQuantidade de comparacoes: %d\n", menor_num_comparacoes);
            break;

        case 5:
            printf("\nEncerrando programa...");
            break;

        default:
            printf("\nOpcao invalida. Tente novamente.");
    }
} while (opcao != 5);

free(vetor_original);
free(vetor_ordenado_bubble);
free(vetor_ordenado_select);
free(vetor_ordenado_insertion);

return 0;
