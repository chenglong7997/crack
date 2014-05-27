/*
 *given two sorted list, return a new list represendting the intersection of the two lists
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>
#include "sorted_merge_14.c"

void sorted_intersect_test();
node_t* sorted_intersect(node_t* a, node_t* b);

int main()
{
    sorted_intersect_test();
}

void sorted_intersect_test()
{
    node_t* a = build_n_list(20);
    node_t* b = build_n_list(40);

    print_list(a);
    print_list(b);

    merge_sort(&a);
    merge_sort(&b);

    printf("after sort\n");
    print_list(a);
    print_list(b);
    
    node_t* intersect = sorted_intersect(a, b);

    print_list(intersect);
}

//comupte a sorted list that represents the intersection of two given sorted lists
node_t* sorted_intersect(node_t* a, node_t* b)
{
    node_t dummy;
    node_t* tail = &dummy;
    tail->next = NULL;

    while (a && b)
    {
        if (a->data > b->data)
	    b = b->next;
	else if (a->data < b->data)
	    a = a->next;
	else {
	    node_t* insert = (node_t*)malloc(sizeof(node_t));
	    insert->data = a->data;
	    insert->next = NULL;
	    tail->next = insert;
	    tail = insert;
	    a = a->next;
	    b = b->next;
	}
    }

    return dummy.next;
}
