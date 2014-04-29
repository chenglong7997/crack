#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "3.2min_stack.c"

#define N 20

void move(node_t** left, node_t** middle, node_t** right, int num);

void test()
{
    node_t* head = NULL;
    int i = 0;
    for (i = N; i > 0; i--)
        push(&head, i);

    node_t* middle = NULL;
    node_t* right = NULL;

    move(&head, &middle, &right, N);

    for (i = 0; i < N; i++)
        printf(" %d \n", pop(&right));

}

void move(node_t** left, node_t** middle, node_t** right, int num)
{
    if (*left == NULL) return;

    if (num <= 0)
        return;

    move(left, right, middle, num - 1);
    push(right, pop(left));
    move(middle, left, right, num - 1);
}

int main()
{
    test();
}


