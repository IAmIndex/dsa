#include "../queue.h"

#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 2

struct Queue {
    int *v;
    size_t size, capacity, head;
};

static bool resizeQueue(Queue *q) {
    size_t newCapacity = q->capacity * 2;
    
    int *tmp = malloc(newCapacity * sizeof(int));
    if (!tmp) return false;

    for (size_t i = 0; i < q->size; i++)
        tmp[i] = q->v[(q->head + i) % q->capacity];

    free(q->v);
    q->v = tmp;
    q->capacity = newCapacity;
    q->head = 0;

    return true;
}

Queue* createQueue() {
    Queue *newQueue = malloc(sizeof(Queue));

    if (newQueue) {
        newQueue->size = newQueue->head = 0;
        newQueue->capacity = INITIAL_CAPACITY;
        newQueue->v = malloc(INITIAL_CAPACITY * sizeof(int));

        if (!newQueue->v) {
            free(newQueue);
            return NULL;
        }
    }

    return newQueue;
}

bool push(Queue *q, int v) {
    if (!q) return false;

    if (q->size == q->capacity)
        if (!resizeQueue(q)) return false;        

    size_t tail = (q->size + q->head) % q->capacity;
    q->v[tail] = v;
    q->size++;
    return true;
}

bool pop(Queue *q, int *r) {
    if (!q || q->size == 0) return false;

    if (r) *r = q->v[q->head];
    
    q->head = (q->head + 1) % q->capacity;
    q->size--;

    return true;
}

bool peekFront(const Queue *q, int *r) {
    if (!q || q->size == 0) return false;

    if (r) *r = q->v[q->head];

    return true;
}

bool peekBack(const Queue *q, int *r) {
    if (!q || q->size == 0) return false;

    if (r) *r = q->v[(q->head + q->size - 1) % q->capacity];

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
    if (!q || q->size == 0) {
        printf("\n[ Empty Queue ]\n");
        return;
    }

    printf("\n[Front] ");
    for (size_t i = 0; i < q->size; i++) {
        size_t idx = (q->head + i) % q->capacity;
        printf("%d <- ", q->v[idx]);
    }
    printf("[Back]\n");
}

void clearQueue(Queue *q) {
    if (!q) return;

    q->size = 0;
    q->head = 0;

    int *tmp = realloc(q->v, INITIAL_CAPACITY * sizeof(int));
    if (tmp) {
        q->v = tmp;
        q->capacity = INITIAL_CAPACITY;
    }
}

void freeQueue(Queue **q) {
    if (!q || !*q) return;

    free((*q)->v);
    free(*q);

    *q = NULL;
}
