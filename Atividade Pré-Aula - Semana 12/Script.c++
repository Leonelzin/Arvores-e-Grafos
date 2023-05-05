//Douglas Leonel de Almeida
//Matricula - 2110213

#include <iostream>
using namespace std;

class No {
    public:
        int valor;
        No* esquerda;
        No* direita;
        No(int v) {
            valor = v;
            esquerda = nullptr;
            direita = nullptr;
        }
};

class Arvore {
    public:
        No* raiz;
        Arvore() {
            raiz = nullptr;
        }
        void inserir(int valor) {
            No* novo_no = new No(valor);
            if (raiz == nullptr) {
                raiz = novo_no;
            }
            else {
                No* atual = raiz;
                while (true) {
                    if (valor < atual->valor) {
                        if (atual->esquerda == nullptr) {
                            atual->esquerda = novo_no;
                            break;
                        }
                        else {
                            atual = atual->esquerda;
                        }
                    }
                    else {
                        if (atual->direita == nullptr) {
                            atual->direita = novo_no;
                            break;
                        }
                        else {
                            atual = atual->direita;
                        }
                    }
                }
            }
        }
};

int main() {
    Arvore arvore;
    arvore.inserir(53);
    arvore.inserir(30);
    arvore.inserir(14);
    arvore.inserir(39);
    arvore.inserir(9);
    arvore.inserir(23);
    arvore.inserir(34);
    arvore.inserir(49);
    arvore.inserir(72);
    arvore.inserir(61);
    arvore.inserir(84);
    arvore.inserir(79);
    arvore.inserir(2);
    arvore.inserir(3);
    arvore.inserir(27);
    arvore.inserir(31);
    return 0;
}
