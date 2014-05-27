#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void front_back_split_test(int n);
void front_back_split(node_t* source, node_t** frontref, node_t** backref);
/*
int main()
{
    front_back_split_test(1);
    front_back_split_test(2);
    front_back_split_test(3);
    front_back_split_test(4);
    front_back_split_test(5);
    front_back_split_test(50);
}
*/
void front_back_split_test(int n)
{
    printf("split for %d nodes list\n", n);
    node_t* head = build_n_list(n, 100);
    node_t* front = NULL;
    node_t* back = NULL;
    front_back_split(head, &head, &back);
    printf("front\n");
    print_list(head);
    printf("back\n");
    print_list(back);
}


void front_back_split(node_t* source, node_t** frontref, node_t** backref)
{
    if (source == NULL) return;
    node_t* slower = source;
    node_t* faster = source;
    //special case for 1 node, 2,3,4,5 nodes all fits
    while (faster->next != NULL && faster->next->next != NULL)
    {
        slower = slower->next;
	faster = faster->next->next;
    }
    *backref = slower->next;
    slower->next = NULL;
    *frontref = source;
    return;
}
