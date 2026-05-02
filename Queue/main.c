#include "queue.h"
#include <stdio.h>

int main() {
    Queue *q = createQueue();
    
    printQueue(q);

    push(q, 10);
    push(q, 15);
    push(q, 20);

    printQueue(q);

    int back, front;
    peekBack(q, &back);
    peekFront(q, &front);

    printf("Back: %d\tFront: %d\n", back, front);

    size_t size = getSize(q);

    printf("Queue size: %zu - ", size);
    printf("Is empty? %s\n", isEmpty(q)?"Yes":"No");
    
    int popped;
    pop(q, &popped);
    
    printf("Popped: %d\n", popped);
    
    printQueue(q);
    
    clearQueue(q);
    
    size = getSize(q);
    
    printQueue(q);
    printf("Queue size: %zu - ", size);
    printf("Is empty? %s\n", isEmpty(q)?"Yes":"No");
    
    freeQueue(&q);
    
    size = getSize(q);
    
    printQueue(q);
    printf("Queue size: %zu - ", size);
    printf("Is empty? %s\n", isEmpty(q)?"Yes":"No");

    return 0;
}