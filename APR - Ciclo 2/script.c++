//Douglas Leonel de Almeida
//Matricula - 2110213

//Para implementar a estrutura de dados para a busca sequencial e binária das informações dos pacientes, é necessário ter os dados dos pacientes armazenados em uma estrutura de dados que permita a busca eficiente. Uma opção seria utilizar um array de structs para armazenar as informações dos pacientes.

//Para realizar a busca sequencial, é possível implementar uma função que percorre o array e compara os valores de interesse com o valor desejado. Para isso, pode-se utilizar um loop for para percorrer o array e uma estrutura condicional para verificar se o valor desejado é igual ao valor no índice atual do array. Se o valor desejado for encontrado, a função deve retornar o índice do paciente no array. Caso contrário, a função deve retornar -1 para indicar que o paciente não foi encontrado.

//Para realizar a busca binária, é necessário que o array esteja ordenado. Pode-se utilizar uma das funções de ordenação implementadas na APR 1 para ordenar o array antes de realizar a busca binária. A busca binária é uma estratégia que divide o array em duas metades e verifica se o valor desejado está na primeira ou na segunda metade. Esse processo é repetido até que o valor desejado seja encontrado ou até que o array seja reduzido a um único elemento que não é o valor desejado. Se o valor desejado for encontrado, a função deve retornar o índice do paciente no array. Caso contrário, a função deve retornar -1 para indicar que o paciente não foi encontrado.

#include <iostream>

struct Paciente {
    int idade;
    std::string nome;
    // outras informações relevantes
};

int buscaSequencial(Paciente* pacientes, int n, int idade_desejada) {
    int i;
    for(i = 0; i < n; i++) {
        if(pacientes[i].idade == idade_desejada) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(Paciente* pacientes, int n, int idade_desejada) {
    int inicio = 0;
    int fim = n - 1;
    int meio;
    while(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if(pacientes[meio].idade == idade_desejada) {
            return meio;
        } else if(pacientes[meio].idade < idade_desejada) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    Paciente pacientes[5];
    // preencher o array de pacientes com informações relevantes

    // buscar um paciente com idade 30 usando busca sequencial
    int indice_sequencial = buscaSequencial(pacientes, 5, 30);
    if(indice_sequencial != -1) {
        std::cout << "Paciente encontrado: " << pacientes[indice_sequencial].nome << std::endl;
    } else {
        std::cout << "Paciente nao encontrado." << std::endl;
    }

    // ordenar o array de pacientes por idade (usando uma função de ordenação apropriada)

    // buscar um paciente com idade 30 usando busca binária
    int indice_binaria = buscaBinaria(pacientes, 5, 30);
    if(indice_binaria != -1) {
        std::cout << "Paciente encontrado: " << pacientes[indice_binaria].nome << std::endl;
    } else {
        std::cout << "Paciente nao encontrado." << std::endl;
    }

    return 0;
}

//Essas funções podem ser chamadas a partir do main ou de outras funções que precisem realizar uma busca sequencial ou binária nos dados dos pacientes. 

//É importante lembrar que a busca binária só funciona se o array estiver ordenado previamente.