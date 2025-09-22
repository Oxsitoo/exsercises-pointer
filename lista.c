#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Crear un nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: memoria no reservada\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Crear una lista con n nodos
struct Node* createList(int n) {
    if (n <= 0) return NULL;

    struct Node* head = createNode(1); // primer nodo con valor 1
    struct Node* temp = head;

    for (int i = 2; i <= n; i++) {
        temp->next = createNode(i); // siguiente nodo
        temp = temp->next;          // avanzar
    }

    return head;
}

// Imprimir lista
void printList(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
        if (count % 20 == 0) printf("\n"); // salto cada 20 nodos
    }
    printf("NULL\n");
}

// Liberar memoria de la lista
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n = 100000000;
    struct Node* head = createList(n);

    // Imprimir la lista
    printList(head);

    // Liberar memoria
    freeList(head);

    return 0;
}
