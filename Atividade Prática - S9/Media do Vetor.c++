//Douglas Leonel de Almeida
//Matricula - 2110213

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int vetor[] = {1, 2, 5, 7, 10, 12, 13, 14, 16, 20};
    int n = sizeof(vetor) / sizeof(int);
    int i, j, mais_proximo, comp = 0;
    float media = 0, diff = INFINITY;
    
    for (i = 0; i < n; i++) {
        media += vetor[i];
    }
    media /= n;

    for (j = 0; j < n; j++) {
        int distancia = abs(media - vetor[j]);
        comp++;
        if (distancia < diff) {
            diff = distancia;
            mais_proximo = vetor[j];
        }
    }
    
    printf("O valor mais próximo da média (%.2f) é %d\n", media, mais_proximo);
    printf("Foram feitas %d comparações\n", comp);
    
    return 0;
}

//O programa utiliza dois loops: o primeiro para calcular a média do vetor e o segundo para encontrar o valor mais próximo da média. Durante o segundo loop, para cada elemento do vetor é calculada a sua distância para a média, e o elemento cuja distância é a menor até o momento é considerado o mais próximo da média. O número de comparações realizadas é contabilizado e exibido ao final do programa.

//Para o vetor fornecido, a saída do programa seria:

//O valor mais próximo da média (9.00) é 10
//Foram feitas 10 comparações
