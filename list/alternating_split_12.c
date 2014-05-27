/*
 *takes one list and divides up its nodes to make two smaller lists. The sublists should be made
 *from alternating elements in the original list.
 *EX: {a,b,a,b,a} => {a,a,a} {b,b}
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>
#include "move_node_11.c"

void alternating_split_test();
void alternating_split(node_t* src, node_t** aref, node_t** bref);

int main()
{
    alternating_split_test();
}

void alternating_split_test()
{
    node_t* head = build_n_list(20);
    node_t* a = NULL;
    node_t* b = NULL;
    
    print_list(head);
    alternating_split(head, &a, &b);
    
    print_list(head);
    print_list(a);
    print_list(b);
}

void alternating_split(node_t* src, node_t** aref, node_t** bref)
{
    int turn = 0;
    while (src != NULL)
    {
        if (turn == 0)
	{
            move_node(aref, &src);
	    turn = 1;
	}
	else
	{
            move_node(bref, &src);
            turn = 0;
        }
    }
}
/*
{
    while (src != NULL)
    {
        move_node(aref, &src);
	if (src != NULL)
	    move_ndoe(bref, &src);
    }
}
*/
