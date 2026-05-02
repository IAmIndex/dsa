#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

static struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode) {
        newNode->v = v;
        newNode->next = NULL;
    }

    return newNode;
}

Stack* createStack() {
    Stack *newStack = malloc(sizeof(Stack));

    if (newStack) {
        newStack->top = NULL;        
    }

    return newStack;
}

void push(Stack *s, int v) {
    if (!s) return;

    struct Node *newNode = createNode(v);
    if (!newNode) return;
    
    newNode->next = s->top;
    s->top = newNode;
}

bool pop(Stack *s, int *r) {
    if (!s || !s->top) return false;

    struct Node *tmp = s->top;
    if (r) *r = tmp->v;
    
    s->top = s->top->next;
    free(tmp);

    return true;
}

bool peek(const Stack *s, int *r) {
    if (!s || !s->top) return false;

    if (r) *r = s->top->v;

    return true;
}

bool isEmpty(const Stack *s) {
    return s && s->top == NULL;
}

void printStack(const Stack *s) {
    if (!s || !s->top) {
        printf("\n[ Empty Stack ]\n");
        return;
    }

    printf("\n-------\n");
    struct Node *tmp = s->top;
    while (tmp) {
        printf("| %3d |\n", tmp->v);
        tmp = tmp->next;
    }
    printf("-------\n");
}

void clearStack(Stack *s) {
    if (!s) return;

    while (pop(s, NULL));
}

void freeStack(Stack **s) {
    if (!s || !*s) return;

    clearStack(*s);

    free(*s);

    *s = NULL;
}
