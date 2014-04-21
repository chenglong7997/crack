#include <stdio.h>
#include <stdlib.h>

#ifndef BUILD_H
#define BUILD_H

typedef struct node {
    int data;
    struct node *next;
}node_t;

node_t* build_n_list(int n)
{
    node_t* array = (node_t*)malloc(sizeof(node_t) * n);
    for (int i = 0; i < n - 1; i++)
    {
        array[i].next = array + i + 1;
	array[i].data = rand() % 100;
    }
    array[n - 1].next = NULL;
    array[n - 1].data = rand() % 100;
    return array;
}

node_t* build_simple_list()
{
    node_t* head = (node_t*)malloc(sizeof(node_t));
    node_t* node1 = (node_t*)malloc(sizeof(node_t));
    node_t* node2 = (node_t*)malloc(sizeof(node_t));
    node_t* node3 = (node_t*)malloc(sizeof(node_t));
    node_t* node4 = (node_t*)malloc(sizeof(node_t));
    if (head == NULL || node1 == NULL || node2 == NULL || 
		    node3 == NULL || node4 == NULL) exit(1);

    head->data = 1;
    node1->data = 2;
    node2->data = 3;
    node3->data = 5;
    node4->data = 4;

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    return head;
}

void print_list(node_t* list)
{
    while (list != NULL)
    {
        printf(" %d ", list->data);
	list = list->next;
    }
    printf("\n");
}

#endif
