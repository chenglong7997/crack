#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "3.2min_stack.c"

void queue_test();
void enqueue(node_t** headref, int value);
int dequeue(node_t** headref);

int main()
{
    queue_test();
}

void queue_test()
{
    node_t* head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 5);
    enqueue(&head, 3);

    printf("%d\n", dequeue(&head));
    printf("%d\n", dequeue(&head));
    printf("%d\n", dequeue(&head));
}

node_t* s2 = NULL;

void enqueue(node_t** headref, int value)
{
    while (s2 != NULL)
        push(headref, pop(&s2));

    push(headref, value);
}

int dequeue(node_t** headref)
{
    while (*headref != NULL)
        push(&s2, pop(headref));

    return pop(&s2);
}
