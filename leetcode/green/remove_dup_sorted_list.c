/* 1. Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 * 2. Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "sorted_merge_14.c"
/*
void remove_dup(node_t *root)
{
    if (root == NULL) return;
    node_t* fast = root;
    node_t* slow = root;

    while(slow->next)
    {
        fast = slow->next;
	if (slow->data == fast->data)
	{
	    slow->next = fast->next;
	    //fast = fast->next;
	}
	else
	{
	    slow = slow->next;
	}
    }
}
*/

void remove_dup2(node_t **root)
{
    if (*root == NULL || (*root)->next == NULL) return;
    node_t* root_next = (*root)->next;
   
    //fix the root first
    while (root_next && (*root)->data == (root_next)->data)
    {
        root_next = root_next->next;
    }
    if (root_next == NULL)
    {
        *root = NULL;
	return;
    }
    else *root = root_next;

    node_t *pslow = *root;
    node_t *pfast = (*root)->next;
    //for all remaining nodes
    while (pslow && pfast)
    {
        pfast = pslow->next;
	while (pfast && pfast->next && pfast->data == pfast->next->data)
	{
	    pfast = pfast->next;
	}
	if (!pfast || !pfast->next) return;
	else
	{
            pslow->next = pfast->next;
            pslow = pslow->next;
	}
    }
}


void test()
{
    node_t* lista = build_n_list(50, 100);
    merge_sort(&lista);
    print_list(lista);

    remove_dup2(&lista);
    print_list(lista);
}

int main()
{
    test();
}
