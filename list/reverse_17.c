/*
 *reverse list: two methods
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void reverse_test();
void reverse(node_t** headref);
void recursive_reverse(node_t** headref);

int main()
{
    reverse_test();
}

void reverse_test()
{
    node_t* head = build_n_list(10);
    print_list(head);
    recursive_reverse(&head);
    //free
    print_list(head);
}

void reverse(node_t** headref)
{
    if (*headref == NULL)
        return;

    node_t* pre = *headref; 
    node_t* cur = (*headref)->next; 
    node_t* fwd = (*headref)->next;
    
    while (cur != NULL)
    {
        fwd = cur->next;
        cur->next = pre;
	pre = cur;
	cur = fwd;
    }
    (*headref)->next = NULL;
    *headref = pre;
}

void recursive_reverse(node_t** headref)
{
    if (*headref == NULL || (*headref)->next == NULL)
        return;

    node_t* rest = (*headref)->next;
    recursive_reverse( &rest );
    (*headref)->next->next = *headref;
    (*headref)->next = NULL;
    *headref = rest;
}


