/*
 *find all root-to-leaf paths where each path's sum equals the given sum
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"

void print_array(int path[], int len)
{
    for (int i = 0; i < len; i++)
	    printf("%d ", path[i]);
    printf("\n");
}


void path_sum2(node_t* root, int sum, int *path, int level)
{
    if (root == NULL) return;

    path[level] = root->data;
    level++;
    sum -= root->data;

    if (!root->left && !root->right && !sum)
	    print_array(path, level);

    path_sum2(root->left, sum, path, level);
    path_sum2(root->right, sum, path, level);
}

int main()
{
    node_t* root = build_n_tree(100, 1);
    int path[200] = {};
    path_sum2(root, 50, path, 0);
}
