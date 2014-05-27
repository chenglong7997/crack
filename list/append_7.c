/*
 *append list 'b' to the end of list 'a', and sets 'b' to NULL
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void append_test();
void append(node_t** aref, node_t** bref);

int main()
{
    append_test();
}

void append_test()
{
    node_t* ahead = build_simple_list();
    node_t* bhead = build_simple_list();
    append(&ahead, &bhead);
    print_list(ahead);
}

void append(node_t** aref, node_t** bref)
{
    if (*aref == NULL)
    {
        *aref = *bref;
	*bref = NULL;
	return;
    }
    if (*bref == NULL)
        return;
    node_t* cur = *aref;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = *bref;
    *bref = NULL;
    return;
}
