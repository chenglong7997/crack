/*
 *write code to partition a linked list around a value x, such that all nodes
 *less than x come before all nodes greater than or equal to x
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void swap_data(node_t* left, node_t* right);
void partition(node_t* head, int value);
void partition_test();

int main()
{
    partition_test();
}

void partition_test()
{
    node_t* head = build_n_list(40, 100);
    print_list(head);

    partition(head, 9);
    print_list(head);
}


//1. build a small list and big list, combine. too complicate
//2. like this, just swap value
void partition(node_t* head, int value)
{
    if (head == NULL) return;
    node_t* slow = head;
    node_t* fast = head;
    while (fast && slow)
    {
        while (slow != NULL)
        {
            if (slow->data < value)
                slow = slow->next;
	    else
                break;
        }
        
	fast = slow;
        while (fast != NULL)
        {
            if (fast->data >= value)
                fast = fast->next;
	    else
                break;
        }
        if (fast && slow)
            swap_data(slow, fast);
    }
}

void swap_data(node_t* left, node_t* right)
{
    printf("left %d, right %d\n", left->data, right->data);
    int tmp = left->data;
    left->data = right->data;
    right->data = tmp;
}
