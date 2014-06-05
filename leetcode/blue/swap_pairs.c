/*
 *
 *Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"

void swap_pairs(node_t** head)
{
    if (*head == NULL || (*head)->next == NULL) return;
    node_t* pre = *head;
    node_t* cur = (*head)->next;
    node_t* front = (*head)->next->next;
    *head = (*head)->next;
    node_t* last = pre;
    while (cur && front)
    {
        last = pre;
        pre->next = cur->next;
	cur->next = pre;
	
	pre = front;
	cur = front->next;
	
	last->next = cur;
	if (cur) front = cur->next;
	else break;

    }

    //do one more time
    if (cur != NULL)
    {
        pre->next = NULL;
	cur->next = pre;
        last->next = cur;
    } else
    {
        last->next = pre;
    }
}


void test()
{
    node_t* head = build_n_list(10);
    print_list(head);
    swap_pairs(&head);
    print_list(head);
    
    head = build_n_list(9);
    print_list(head);
    swap_pairs(&head);
    print_list(head);
}

int main()
{
    test();
}
