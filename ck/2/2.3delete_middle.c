/*
 *implement an algorithm to delete a node in the middle of a singly linked list
 *,given only access to that node
 * */


#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>
#include "2.2kth.c"

void delete_middle_test();
void delete_middle(node_t* node, node_t* target);

int main()
{
    delete_middle_test();
}

void delete_middle_test()
{
    node_t* head = build_n_list(40, 100);
    print_list(head);
    node_t* target = get_kth_last(head, 8);
    delete_middle(head, target);
    print_list(head);
}

void delete_middle(node_t* node, node_t* target)
{
    if (target->next == NULL) assert(0);
    //target is the head
    if (node->next == target->next) assert(0);

    target->data = target->next->data;
    target->next = target->next->next;

    return;
}
