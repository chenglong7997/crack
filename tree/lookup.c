#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "bfs.cc"

void lookup_test();
int lookup(node_t* root, int target);

int main()
{
    lookup_test();
}

void lookup_test()
{
    node_t* root = build_n_tree(20, 1);
    bfs(root);
    int ret = lookup(root, 7);
    printf("%d\n", ret);
}

int lookup(node_t* root, int target)
{
    if (root == NULL)
        return 0;
    printf("root->data %d \n", root->data);
    if (root->data == target)
        return 1;
    else {
        if (root->data < target)
            return (lookup(root->right, target));
	else
	    return (lookup(root->left, target));
    }
}
