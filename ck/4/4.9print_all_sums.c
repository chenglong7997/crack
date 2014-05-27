/*
 *Print all paths which sum to a give value.
 *
 * note that a path can start or end anywhere in the tree
 *
 * similar question: start from root, end with a leaf node (stanford)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "build.h"
#include "bfs.cc"

void print_array(int* path, int start, int end)
{
    for (int i = start; i <= end; i++)
	    printf(" %d ", path[i]);
    printf("\n");
}

void find_sum(node_t* root, int sum, int* path, int level)
{
    if (root == NULL) return;

    path[level] = root->data;
    int tmp = 0;
    for (int i = level; i >= 0; i--)
    {
        tmp += path[i];
	if (tmp == sum)
            print_array(path, i, level);
    }

    find_sum(root->left, sum, path, level + 1);
    find_sum(root->right, sum, path, level + 1);

    return;
}

void test()
{
    node_t* root = build123();
    int path[200] = {};
    find_sum(root, 4, path, 0);
}

int main()
{
    test();
}
