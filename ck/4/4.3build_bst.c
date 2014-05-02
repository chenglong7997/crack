#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bfs.cc"

node_t* build_bst(int *array, int start, int end)
{
    if (array == NULL) return NULL;
    if (start >= end) return NULL;

    node_t* root = new_node(array[(start + end) / 2]);
    root->left = build_bst(array, start, (start + end) / 2);
    root->right = build_bst(array, (start + end) / 2 + 1, end);
    return root;
}

void test()
{
    int array[100] = {};
    for (int i = 0; i < 100; ++i)
        array[i] = i;

    node_t* root = build_bst(array, 0, 100);

    bfs(root);
}

int main()
{
    test();
}
