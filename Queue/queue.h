#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Queue Queue;

Queue* createQueue();

bool push(Queue *q, int v);
bool pop(Queue *q, int *r);

bool peekFront(const Queue *q, int *r);
bool peekBack(const Queue *q, int *r);
bool isEmpty(const Queue *q);

size_t getSize(const Queue *q);

void printQueue(const Queue *q);
void clearQueue(Queue *q);
void freeQueue(Queue **q);

#endif
