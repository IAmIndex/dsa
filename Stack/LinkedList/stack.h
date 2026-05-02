#ifndef STACK_LL
#define STACK_LL

#include <stdbool.h>

typedef struct Stack Stack;

Stack* createStack();

void push(Stack *s, int v);
bool pop(Stack *s, int *r);

bool peek(const Stack *s, int *r);
bool isEmpty(const Stack *s);

void printStack(const Stack *s);
void clearStack(Stack *s);
void freeStack(Stack **s);

#endif