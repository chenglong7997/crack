/*
 *minimum depth of binary tree
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"

int min_depth(node_t* root)
{
    if (root == NULL) return 0;
    int left_min = min_depth(root->left);
    int right_min = min_depth(root->right);

    if (left_min == 0 && right_min == 0) return 1;
    //if one is empty, use the other one's height set the current's height
    if (left_min == 0) left_min = INT_MAX;
    if (right_min == 0) right_min = INT_MAX;

    return left_min > right_min? right_min + 1 : left_min + 1;
}

int main()
{
    node_t* root = build123();

    printf("min depth %d\n", min_depth(root));
}

