//Douglas Leonel de Almeida
//Matricula - 2110213

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó da árvore
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// a. Algoritmo recursivo para contar o número de nós em uma árvore binária
int countNodesRecursive(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodesRecursive(root->left) + countNodesRecursive(root->right);
    }
}

// a. Algoritmo não recursivo para contar o número de nós em uma árvore binária
int countNodesNonRecursive(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    struct Node* stack[100]; // Pilha para percorrer a árvore
    int top = -1;

    stack[++top] = root;
    while (top >= 0) {
        struct Node* current = stack[top--];
        count++;

        if (current->left != NULL) {
            stack[++top] = current->left;
        }
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
    }

    return count;
}

// b. Algoritmo recursivo para calcular a soma dos conteúdos dos nós em uma árvore binária
int sumNodesRecursive(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->data + sumNodesRecursive(root->left) + sumNodesRecursive(root->right);
    }
}

// b. Algoritmo não recursivo para calcular a soma dos conteúdos dos nós em uma árvore binária
int sumNodesNonRecursive(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;
    struct Node* stack[100]; // Pilha para percorrer a árvore
    int top = -1;

    stack[++top] = root;
    while (top >= 0) {
        struct Node* current = stack[top--];
        sum += current->data;

        if (current->left != NULL) {
            stack[++top] = current->left;
        }
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
    }

    return sum;
}

// c. Algoritmo recursivo para calcular a altura de uma árvore binária
int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

// Função principal para testar os algoritmos
int main() {
    // Criando uma árvore binária de exemplo
    struct Node* root = create

