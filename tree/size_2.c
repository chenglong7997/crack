#include <stdio.h>
#include <stdlib.h>
#include "build.h"

void size_test();
int size(node_t* root);

int main()
{
    size_test();
}

void size_test()
{
    node_t* root = build_n_tree(24, 0);
    printf("size %d\n", size(root));
}

int size(node_t* root)
{
    int num = 0;
    if (root == NULL)
        return 0;
    else
    {
        num += size(root->left) + size(root->right) + 1;
        return num;
    }
}
