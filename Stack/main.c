#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Stack *s = createStack();

    // Initial state
    printStack(s);

    // Test insertion
    push(s, 10);
    push(s, 15);
    push(s, 20);

    // New filled state
    printStack(s);

    // Test peeking top
    int peeked;

    if (peek(s, &peeked))
        printf("Peeked value: %d\n", peeked);
    else
        printf("Nothing to peek!\n");
    
    // Test popping
    int popped;
    
    if (!pop(s, &popped))
        popped = 0;
    
    // State after popping && peeking
    printStack(s);

    // Frees the stack to exit program
    freeStack(&s);

    // State after freed
    printStack(s);

    return 0;
}
