/*
 *design a stack which, in addition to push and pop, also has a function min which
 *returns the minimum element?
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    int data;
    int min;
    struct node* next;
}node_t;

node_t* new_node(int value)
{
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = value;
    tmp->next = NULL;
    tmp->min = value;

    return tmp;
}

void push(node_t** headref, int value)
{
    node_t* tmp = new_node(value);
    if (*headref == NULL)
        *headref = tmp;
    else
    {
	tmp->min = tmp->data > (*headref)->min ? (*headref)->min : tmp->data;
        tmp->next = *headref;
	*headref = tmp;
    }
}

int peek(node_t** headref)
{
    if (*headref == NULL) assert(0);
    return (*headref)->data;
}

int pop(node_t** headref)
{
    if (*headref == NULL) assert(0);
    int tmp = (*headref)->data;
    *headref = (*headref)->next;
    return tmp;
}

int min(node_t* head)
{
    if (head == NULL) assert(0);
    return head->min;
}

void stack_test()
{
    node_t* head = NULL;
    push(&head, 5);
    push(&head, 8);
    push(&head, 1);
    printf("min %d\n", min(head));
    printf("pop %d\n", pop(&head));
    
    printf("min %d\n", min(head));
    printf("pop %d\n", pop(&head));
    
    printf("min %d\n", min(head));
    printf("pop %d\n", pop(&head));
}
/*
int main()
{
    stack_test();
}
*/

