#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next;
} Node;

// Utils
Node* createNode(const int v) {
    Node *newNode = malloc(sizeof(Node));

    if (!newNode) {
        fprintf(stderr, "\nErro ao alocar memória (%zu bytes)!\n", sizeof(Node));
        exit(1);
    }

    newNode->v = v;
    newNode->next = NULL;

    return newNode;
}

// Insertion
void insertHead(Node **h, const int v) {
    if (!h) return;

    Node *newNode = createNode(v);

    newNode->next = *h;
    *h = newNode;
}

void insertTail(Node **h, const int v) {
    if (!h) return;

    Node *newNode = createNode(v);

    Node **tmp = h;
    while (*tmp)
        tmp = &((*tmp)->next);
    
    *tmp = newNode;
}

// Removal
void removeHead(Node **h) {
    if (!h || !*h) return;
    
    Node *tmp = *h;
    *h = (*h)->next;
    free(tmp);
}

void removeTail(Node **h) {
    if (!h || !*h) return;

    if (!(*h)->next) {
        free(*h);
        *h = NULL;
        return;
    }

    Node *tmp = *h;
    while (tmp->next->next)
        tmp = tmp->next;
    
    free(tmp->next);
    tmp->next = NULL;
}

// Others (just so I don't name them Utils again)
void printLinkedList(const Node *h) {
    const Node *tmp = h;

    while (tmp) {
        printf("%d -> ", tmp->v);
        tmp = tmp->next;
    }

    printf("NULL\n");
}

void freeLinkedList(Node **h) {
    if (!h) return;

    while (*h)
        removeHead(h);
}

int main() {
    Node *head = NULL;

    printLinkedList(head);

    insertHead(&head, 10);
    insertHead(&head, 0);
    insertTail(&head, 20);
    insertTail(&head, 30);

    printLinkedList(head);

    removeHead(&head);
    removeTail(&head);
    
    printLinkedList(head);

    freeLinkedList(&head);

    printLinkedList(head);

    return 0;
}
