#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next, *prev;
} Node;

Node* createNode(int v) {
    Node *newNode = malloc(sizeof(Node));

    if (!newNode) {
        fprintf(stderr, "\nErro ao alocar memória (%zu bytes)!", sizeof(Node));
        exit(1);
    }

    newNode->v = v;
    newNode->prev = newNode->next = NULL;

    return newNode;
}

void insertHead(Node **h, int v) {
    if (!h) return;

    Node *newNode = createNode(v);

    newNode->next = *h;
    if (*h) (*h)->prev = newNode;
    *h = newNode;
}

void insertTail(Node **h, int v) {
    if (!h) return;

    Node *newNode = createNode(v);

    if (!*h) {
        *h = newNode;
        return;
    }

    Node *tmp = *h;
    while (tmp->next)
        tmp = tmp->next;

    newNode->prev = tmp;
    tmp->next = newNode;
}

void removeHead(Node **h) {
    if (!h || !*h) return;

    Node *tmp = *h;
    *h = (*h)->next;

    if (*h) (*h)->prev = NULL;

    free(tmp);
}

void removeTail(Node **h) {
    if (!h || !*h) return;

    Node *tmp = *h;
    while (tmp->next)
        tmp = tmp->next;
    
    if (tmp->prev)
        tmp->prev->next = NULL;
    else
        *h = NULL;

    free(tmp);
}

void printList(const Node *h) {
    const Node *tmp = h;
    printf("NULL <-> ");
    while (tmp) {
        printf("%d <-> ", tmp->v);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void printListReverse(const Node *h) {
    const Node *tmp = h;
    while (tmp->next)
        tmp = tmp->next;

    printf("NULL <-> ");
    while (tmp) {
        printf("%d <-> ", tmp->v);
        tmp = tmp->prev;
    }
    printf("NULL\n");
}

void freeList(Node **h) {
    if (!h) return;

    while (*h)
        removeHead(h);
}

int main() {
    Node *head = NULL;

    printList(head);

    insertHead(&head, 10);
    insertHead(&head, 0);
    insertTail(&head, 20);
    insertTail(&head, 30);

    printList(head);
    printListReverse(head);
    
    removeHead(&head);
    removeTail(&head);
    
    printList(head);
    printListReverse(head);

    freeList(&head);

    printList(head);

    return 0;
}
