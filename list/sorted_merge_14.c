#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>
#include "front_back_split_9.c"

void merge_sort_test();
node_t* sorted_merge(node_t* a, node_t* b);
void merge_sort(node_t** headref);
/*
int main()
{
    merge_sort_test();
}
*/
void merge_sort_test()
{
    node_t* lista = build_n_list(50);
    merge_sort(&lista);
    print_list(lista);
}

node_t* sorted_merge(node_t* a, node_t* b)
{
    node_t dummy;
    node_t* tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
	{
	    tail->next = a;
	    tail = a;
	    a = a->next;
	} else {
	    tail->next = b;
	    tail = b;
	    b = b->next;
	}
    }
    if (a != NULL)
        tail->next = a;
    else
        tail->next = b;
    return dummy.next;
}

void merge_sort(node_t** headref)
{
    node_t* front = NULL;
    node_t* back = NULL;
    if (*headref == NULL || (*headref)->next == NULL )
        return;
    front_back_split(*headref, &front, &back);
    merge_sort(&front);
    merge_sort(&back);
    *headref = sorted_merge(front, back);
}
