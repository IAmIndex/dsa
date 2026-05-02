#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct Stack Stack;

Stack* createStack();

bool push(Stack *s, int v);
bool pop(Stack *s, int *r);

bool peek(const Stack *s, int *r);
bool isEmpty(const Stack *s);

void printStack(const Stack *s);
void clearStack(Stack *s);
void freeStack(Stack **s);

#endif
