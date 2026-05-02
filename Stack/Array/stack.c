#include "../stack.h"

#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 2

struct Stack {
    int *v;
    size_t size, capacity;
};

Stack* createStack() {
    Stack *newStack = malloc(sizeof(Stack));

    if (newStack) {
        newStack->capacity = INITIAL_CAPACITY;
        newStack->size = 0;
        newStack->v = malloc(INITIAL_CAPACITY * sizeof(int));

        if (!newStack->v) {
            free(newStack);
            return NULL;
        }
    }

    return newStack;
}

bool push(Stack *s, int v) {
    if (!s) return false;

    if (s->size == s->capacity) {
        int newCapacity = s->capacity * 2;
        int *tmp = realloc(s->v, newCapacity * sizeof(int));

        if (!tmp) return false;

        s->capacity = newCapacity;
        s->v = tmp;
    }

    s->v[s->size++] = v;
    return true;
}

bool pop(Stack *s, int *r) {
    if (!s || s->size == 0) return false;

    if (r) *r = s->v[--s->size];
    else s->size--;

    return true;
}

bool peek(const Stack *s, int *r) {
    if (!s || s->size == 0) return false;

    if (r) *r = s->v[s->size - 1];

    return true;
}

bool isEmpty(const Stack *s) {
    return !s || s->size == 0;
}

void printStack(const Stack *s) {
    if (!s || s->size == 0) {
        printf("\n[ Empty Stack ]\n");
        return;
    }

    printf("\n-------\n");
    for (int i = s->size - 1; i >= 0; i--)
        printf("| %3d |\n", s->v[i]);
    printf("-------\n");
}

void clearStack(Stack *s) {
    if (!s) return;

    s->size = 0;

    int *tmp = realloc(s->v, INITIAL_CAPACITY * sizeof(int));
    if (tmp) {
        s->v = tmp;
        s->capacity = INITIAL_CAPACITY;
    }
}

void freeStack(Stack **s) {
    if (!s || !*s) return;

    free((*s)->v);
    free(*s);
    *s = NULL;
}
