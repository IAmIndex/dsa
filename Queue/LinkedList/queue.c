#include "../queue.h"

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node *prev, *next;
};

struct Queue {
    struct Node *back, *front;
    size_t size;
};

static struct Node* createNode(int v) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode) {
        newNode->v = v;
        newNode->next = newNode->prev = NULL;
    }
    
    return newNode;
}

Queue* createQueue() {
    Queue *newQueue = malloc(sizeof(Queue));

    if (newQueue) {
        newQueue->back = newQueue->front = NULL;
        newQueue->size = 0;
    }

    return newQueue;
}

bool push(Queue *q, int v) {
    if (!q) return false;

    struct Node *newNode = createNode(v);
    if (!newNode) return false;

    if (q->size == 0) q->front = q->back = newNode;
    else {
        newNode->next = q->back;
        q->back->prev = newNode;
        q->back = newNode;
    }

    q->size++;

    return true;
}

bool pop(Queue *q, int *r) {
    if (!q || q->size == 0) return false;

    struct Node *tmp = q->front;

    q->front = q->front->prev;
    
    if (q->front) q->front->next = NULL;
    else q->back = NULL;

    if (r) *r = tmp->v;
    free(tmp);

    q->size--;

    return true;
}

bool peekFront(const Queue *q, int *r) {
    if (!q || !q->front) return false;

    if (r) *r = q->front->v;

    return true;
}

bool peekBack(const Queue *q, int *r) {
    if (!q || !q->back) return false;

    if (r) *r = q->back->v;

    return true;
}

bool isEmpty(const Queue *q) {
    return !q || q->size == 0;
}

size_t getSize(const Queue *q) {
    if (!q) return 0;

    return q->size;
}

void printQueue(const Queue *q) {
    if (!q || !q->front) {
        printf("\n[ Empty Queue ]\n");
        return;
    }

    struct Node *tmp = q->front;
    printf("\n[Front] ");
    while (tmp) {
        printf("%d <- ", tmp->v);
        tmp = tmp->prev;
    }
    printf("[Back]\n");
}

void clearQueue(Queue *q) {
    if (!q) return;

    while (pop(q, NULL));
}

void freeQueue(Queue **q) {
    if (!q || !*q) return;

    clearQueue(*q);
    free(*q);
    *q = NULL;
}
