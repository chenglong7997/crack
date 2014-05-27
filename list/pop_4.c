/*
 *takes a non-empty list, deletes the head node, and returns the head node's data
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void pop_test();
int pop(node_t** list);

int main()
{
    pop_test();
}

void pop_test()
{
    node_t* head = build_simple_list();
    int a = pop(&head);
    int b = pop(&head);
    int c = pop(&head);
}

int pop(node_t** list)
{
    node_t* cur = NULL;
    int value = 0;
    if (*list != NULL)
    {
        cur = *list;
        *list = (*list)->next;
	value = cur->data;
	free(cur);
	return value;
    } else {
        printf("Empty!\n");
        //exit(1);
    }
    assert(0);
}

/*
 * what should return in case of error situation?
 *1. exit(1) 2. assert()
 */
