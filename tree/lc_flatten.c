#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "insert.c"


void helper(node_t* root, node_t *& prev)
{
    if (!root) return;

    prev = root;
    helper(root->left, prev);
    
    node_t* tmp = root->right;
    root->right = root->left;
    prev->right = tmp;

    helper(tmp, prev);

}

void flatten(node_t* root)
{
    node_t* prev = NULL;
    helper(root, prev);
}

void test()
{
    node_t* root = build_bst(30);
    bfs(root);
    printf("\n");

    flatten(root);

    while (root != NULL)
    {
        printf("%d  ", root->data);
        root = root->right;
    }
    printf("\n");

}

int main()
{
    test();
}
