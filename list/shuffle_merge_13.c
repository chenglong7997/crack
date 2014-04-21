#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void shuffle_merge_test();
node_t* shuffle_merge(node_t* a, node_t* b);
node_t* append(node_t* tail, node_t* tmp);

int main()
{
    shuffle_merge_test();
}

void shuffle_merge_test()
{
    node_t* a = build_n_list(5);
    node_t* b = build_n_list(7);
    print_list(a);
    print_list(b);
    node_t* c = shuffle_merge(a, b);
    print_list(c);
}

node_t* shuffle_merge(node_t* a, node_t* b)
{
	// love dummy node for tail insertion
    node_t dummy;
    node_t* tail = &dummy;
    tail->next = NULL;

    node_t* tmp;
    while (a != NULL && b != NULL)
    {
	//add two case in while loop to skip use the flag
	tail->next = a;
	tail = a;
	a = a->next;
        
        tail->next = b;
        tail = b;	
	b = b->next;
    }
    if (a != NULL)
        tail->next = a;
    else
        tail->next = b;

    return dummy.next;
}
/*
node_t* append(node_t* tail, node_t* tmp)
{
    tail->next = tmp;
    tmp->next = NULL;
    return tmp;
}*/
