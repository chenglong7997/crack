/*
 *find the 'next' node (eg: in-order successor) of a given node in a bst.
 *
 * You may assume that each node has a link to its parent
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "build.h"
#include "bfs.cc"

node_t* next_in_order(node_t* root, node_t* cur)
{
    if (root == NULL || cur == NULL) return NULL;

    node_t* right = cur->right;
    if (right != NULL)
    {
        while (right->left != NULL)
		right = right->left;
	return right;
    }

    //right == NULL
    while (cur->parent && cur != cur->parent->left)
    {
        cur = cur->parent;
    }

    if (cur->parent == NULL) return NULL;
    else
        return cur->parent;
}

void test()
{
    node_t* root = build_n_tree(23, 0);
    bfs(root);
    node_t* next = next_in_order(root, root->left->right);
    printf("%d\n", next->data);
}

int main()
{
    test();
}
