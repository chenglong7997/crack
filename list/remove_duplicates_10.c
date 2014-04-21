#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>
#include "sorted_insert_6.c"

void remove_duplicates_test();
void remove_duplicates(node_t* list);
void delete_next(node_t* cur);
extern void insert_sort(node_t** list);

int main()
{
    remove_duplicates_test();
}

void remove_duplicates_test()
{
    node_t* head = build_n_list(100);
    
    printf("old list\n");
    print_list(head);
    
    insert_sort(&head);
    printf("sorted list\n");
    print_list(head);
    
    remove_duplicates(head);
    printf("new list\n");
    print_list(head);
}

void remove_duplicates(node_t* list)
{
    if (list == NULL)
        return;

    node_t* cur = list;
    while (cur->next != NULL)
    {
	if (cur->data == cur->next->data)
	    delete_next(cur);
        else
	    cur = cur->next; 
    }

    return;
}

void delete_next(node_t* cur)
{
    cur->next = cur->next->next;
    //free(cur->next);
}
