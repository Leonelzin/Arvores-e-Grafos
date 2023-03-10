//Douglas Leonel de Almeida - 2110213

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void imprimir_pilha(stack<int> pilha) {
    while (!pilha.empty()) {
        cout << pilha.top() << " ";
        pilha.pop();
    }
    cout << endl;
}

void organizar_pilha(stack<int>& pilha) {
    vector<int> elementos;
    while (!pilha.empty()) {
        elementos.push_back(pilha.top());
        pilha.pop();
    }
    sort(elementos.begin(), elementos.end(), greater<int>());
    for (int i = 0; i < elementos.size(); i++) {
        pilha.push(elementos[i]);
    }
}

int main() {
    stack<int> pilha;

    pilha.push(5);
    pilha.push(2);
    pilha.push(7);

    organizar_pilha(pilha);
    imprimir_pilha(pilha);

    return 0;
}
