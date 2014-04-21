#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void sorted_insert_test();
void insert_sort(node_t** list);
void sorted_insert(node_t** list, node_t* new_node);
/*
int main()
{
    sorted_insert_test();
}
*/
void sorted_insert_test()
{
    node_t* head = build_simple_list();
    
    print_list(head);
    
    insert_sort(&head);

    print_list(head);
}

void insert_sort(node_t** list)
{
    node_t* new_list = NULL;
    node_t* cur = *list;
    while (*list != NULL)
    {
	*list = (*list)->next;
        sorted_insert(&new_list, cur);
	cur = *list;
    }
    *list = new_list; 
}

void sorted_insert(node_t** list, node_t* new_node)
{
    node_t* scan = *list;
    if (new_node == NULL) return;
    if (*list == NULL)
    {
        *list = new_node;
        (*list)->next = NULL;
        return;
    }
    //insert to head
    if ((*list)->data > new_node->data)
    {
        new_node->next = *list;
	*list = new_node;
	return;
    }
    //insert to middle
    while (scan != NULL && scan->next != NULL)
    {
        if (scan->data <= new_node->data && new_node->data <= scan->next->data)
	{
            new_node->next = scan->next;
	    scan->next = new_node;
	    return;
	}
	else
	    scan = scan->next;
    }
    //insert to tail
    if (scan->next == NULL)
    {
        scan->next = new_node;
	new_node->next = NULL;
	return;
    }
}


