#include <stdio.h>
#include <stdlib.h>
#include "build.h"

int max_depth(node_t* root);
int max(int a, int b);
void max_depth_test();

int main()
{
    max_depth_test();
}

void max_depth_test()
{
    node_t* root = build_n_tree(50, 0);
    printf("depth %d\n", max_depth(root));
    printf("NULL depth %d\n", max_depth(NULL));
}

int max_depth(node_t* root)
{
    if (root == NULL)
        return 0;
    else
        return max(max_depth(root->left), max_depth(root->right)) + 1;
}

int max(int a, int b)
{
    return a > b? a : b;
}
