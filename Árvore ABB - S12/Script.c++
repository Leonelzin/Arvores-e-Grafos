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

class ABB {
    public:
        No* raiz;
        ABB() {
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
        void pre_ordem(No* no) {
            if (no != nullptr) {
                cout << no->valor << " ";
                pre_ordem(no->esquerda);
                pre_ordem(no->direita);
            }
        }
        void em_ordem(No* no) {
            if (no != nullptr) {
                em_ordem(no->esquerda);
                cout << no->valor << " ";
                em_ordem(no->direita);
            }
        }
        void pos_ordem(No* no) {
            if (no != nullptr) {
                pos_ordem(no->esquerda);
                pos_ordem(no->direita);
                cout << no->valor << " ";
            }
        }
};

int main() {
    ABB arvore;
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

    cout << "Valores na travessia pré-ordem: ";
    arvore.pre_ordem(arvore.raiz);
    cout << endl;

    cout << "Valores na travessia em ordem: ";
    arvore.em_ordem(arvore.raiz);
    cout << endl;

    cout << "Valores na travessia pós-ordem: ";
    arvore.pos_ordem(arvore.raiz);
    cout << endl;

    return 0;
}
