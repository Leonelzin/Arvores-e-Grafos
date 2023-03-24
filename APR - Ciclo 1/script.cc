//Douglas Leonel de Almeida
//Matricula - 2110213

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    int idade;
    char sexo;
    float renda;
    char bairro[50];
    int qtd_moradores;
} Paciente;

void bubbleSort(Paciente* pacientes, int n) {
    int i, j;
    Paciente temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(pacientes[j].idade > pacientes[j+1].idade) {
                temp = pacientes[j];
                pacientes[j] = pacientes[j+1];
                pacientes[j+1] = temp;
            }
        }
    }
}

void selectionSort(Paciente* pacientes, int n) {
    int i, j, min_idx;
    Paciente temp;
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(pacientes[j].idade < pacientes[min_idx].idade) {
                min_idx = j;
            }
        }
        temp = pacientes[min_idx];
        pacientes[min_idx] = pacientes[i];
        pacientes[i] = temp;
    }
}

void insertionSort(Paciente* pacientes, int n) {
    int i, j;
    Paciente key;
    for(i = 1; i < n; i++) {
        key = pacientes[i];
        j = i - 1;
        while(j >= 0 && pacientes[j].idade > key.idade) {
            pacientes[j+1] = pacientes[j];
            j = j - 1;
        }
        pacientes[j+1] = key;
    }
}

void printPacientes(Paciente* pacientes, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Idade: %d, Sexo: %c, Renda: %.2f, Bairro: %s, Qtd. Moradores: %d\n",
               pacientes[i].idade, pacientes[i].sexo, pacientes[i].renda, pacientes[i].bairro, pacientes[i].qtd_moradores);
    }
}

int main() {
    Paciente pacientes[5] = {{20, 'F', 2500.00, "Centro", 2},
                             {23, 'M', 4500.00, "Setor Sul", 3},
                             {60, 'M', 9000.00, "Jardim América", 4},
                             {57, 'F', 1200.00, "Jardim das Américas 2 etapa", 1},
                             {35, 'M', 2000.00, "Recanto do Sol", 2}};

    int n = sizeof(pacientes)/sizeof(pacientes[0]);
    
    // Bubble Sort
    bubbleSort(pacientes, n);
    printf("Bubble Sort:\n");
    printPacientes(pacientes, n);
    
    // Selection Sort
    selectionSort(pacientes, n);
    printf("\nSelection Sort:\n");
    printPacientes(pacientes, n);
    
    // Insertion Sort
    insertionSort(pacientes, n);
    printf("\nInsertion Sort:\n");
    printPacientes(pacientes, n);

    return 0;
}
