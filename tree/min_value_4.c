/*
 *given the bst, return the minimum data value
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "insert.c"
#include "bfs.cc"

int min_value(node_t* root);
void min_value_test();

int main()
{
    min_value_test();
}

void min_value_test()
{
    node_t* root = build_bst(30);
    bfs(root);

    printf("min %d \n", min_value(root));
    
    root = build_bst(20);
    bfs(root);

    printf("min %d \n", min_value(root));
}

int min_value(node_t* root)
{
    node_t* cur = root;
    assert(root != NULL);
    while (cur->left)
        cur = cur->left;
    return cur->data;
}
