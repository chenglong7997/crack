/*
 *write a program to sort a stack in ascending order(with biggest items on top)
 *You may use additional stacks to hold items, but you may not copy the elements
 *into any other data structure
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "3.2min_stack.c"
#include <limits.h>

/*two stack for sorting*/
void sort(node_t** head, node_t** result)
{
    if (*head == NULL) return;
    int cur = pop(head);
    int counter = 0;

    while (*result != NULL)
    {
	if (peek(result) < cur)
            break;
	else
	{
	    push(head, pop(result));
            counter++;
	}
    }
    push(result, cur);

    while (counter--)
    {
        push(result, pop(head));
    }

    sort(head, result);
}

/*three stack for sorting
void sort(node_t** head, node_t** tmp, node_t** result)
{
    int data = INT_MAX;
    int cur = 0;

    if (*head == NULL) return;

    while (*head != NULL)
    {
        cur = pop(head);
        if (data == INT_MAX)
	{
            data = cur;
	}
	else if (data > cur)
	{
	    push(tmp, data);
	    data = cur;
	}
	else
	    push(tmp, cur);
    }

    push(result, data);
    sort(tmp, head, result);
}
*/

void test()
{
    node_t* head = NULL;
    node_t* tmp = NULL;
    node_t* result = NULL;

    push(&head, 3);
    push(&head, 4);
    push(&head, 1);
    push(&head, 2);
    push(&head, 8);
    push(&head, 34);

//    sort(&head, &tmp, &result);

    sort(&head, &result);

    while (result != NULL)
        printf("%d\n", pop(&result));
}

int main()
{
    test();
}


