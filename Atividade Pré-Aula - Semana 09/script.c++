//Douglas Leonel de Almeida
//Matricula - 2110213

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void search(struct Node* head, int x) {
    struct Node* current = head;
    int found = 0;
    while (current != NULL) {
        if (current->data == x) {
            found = 1;
            break;
        }
        current = current->next;
    }
    if (found) {
        printf("Elemento %d encontrado na lista.\n", x);
    } else {
        printf("Elemento %d não encontrado na lista.\n", x);
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    search(head, 2);
    search(head, 4);

    return 0;
}
