//Douglas Leonel de Almeida
//Matricula - 2110213

//Para implementar a estrutura de dados para a busca sequencial e binária das informações dos pacientes, é necessário ter os dados dos pacientes armazenados em uma estrutura de dados que permita a busca eficiente. Uma opção seria utilizar um array de structs para armazenar as informações dos pacientes.

//Para realizar a busca sequencial, é possível implementar uma função que percorre o array e compara os valores de interesse com o valor desejado. Para isso, pode-se utilizar um loop for para percorrer o array e uma estrutura condicional para verificar se o valor desejado é igual ao valor no índice atual do array. Se o valor desejado for encontrado, a função deve retornar o índice do paciente no array. Caso contrário, a função deve retornar -1 para indicar que o paciente não foi encontrado.

//Para realizar a busca binária, é necessário que o array esteja ordenado. Pode-se utilizar uma das funções de ordenação implementadas na APR 1 para ordenar o array antes de realizar a busca binária. A busca binária é uma estratégia que divide o array em duas metades e verifica se o valor desejado está na primeira ou na segunda metade. Esse processo é repetido até que o valor desejado seja encontrado ou até que o array seja reduzido a um único elemento que não é o valor desejado. Se o valor desejado for encontrado, a função deve retornar o índice do paciente no array. Caso contrário, a função deve retornar -1 para indicar que o paciente não foi encontrado.

#include <iostream>
#include <algorithm> // biblioteca para utilizar a função sort
using namespace std;

struct Paciente {
    string nome;
    int idade;
    // outras informações dos pacientes
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
    // exemplo de utilização das funções de busca
    Paciente pacientes[5] = {{"João", 20}, {"Maria", 30}, {"Pedro", 40}, {"Ana", 50}, {"Lucas", 60}};
    int n = 5;
    int idade_desejada = 40;

    // ordena o array de pacientes por idade
    sort(pacientes, pacientes + n, [](Paciente a, Paciente b) {
        return a.idade < b.idade;
    });

    // busca sequencial
    int indice_sequencial = buscaSequencial(pacientes, n, idade_desejada);
    if(indice_sequencial != -1) {
        cout << "Paciente encontrado na posição " << indice_sequencial << " (busca sequencial)" << endl;
    } else {
        cout << "Paciente não encontrado (busca sequencial)" << endl;
    }

    // busca binária
    int indice_binaria = buscaBinaria(pacientes, n, idade_desejada);
    if(indice_binaria != -1) {
        cout << "Paciente encontrado na posição " << indice_binaria << " (busca binária)" << endl;
    } else {
        cout << "Paciente não encontrado (busca binária)" << endl;
    }

    return 0;
}

//Essas funções podem ser chamadas a partir do main ou de outras funções que precisem realizar uma busca sequencial ou binária nos dados dos pacientes. É importante lembrar que a busca binária só funciona se o array estiver ordenado previamente.