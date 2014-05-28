/*
 *print all "root leaf paths"
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "insert.c"

void print_paths_test();
void print_paths(node_t* node);
void print_array(int path[], int path_len);
void print_paths_recur(node_t* node, int path[], int path_len);

int main()
{
    print_paths_test();
}

void print_paths_test()
{
    node_t* root = build123();
    print_paths(root);
    
    root = build_bst(30);
    print_paths(root);
}

void print_paths(node_t* node)
{
    int array[1000];
    print_paths_recur(node, array, 0);
}

void print_paths_recur(node_t* node, int path[], int path_len)
{
    if (node == NULL)
        return;
    path[path_len] = node->data;
    path_len++;

    if (!node->left && !node->right)
    {
        print_array(path, path_len);
    } else {
        print_paths_recur(node->left, path, path_len);
        print_paths_recur(node->right, path, path_len);
    }
}

void print_array(int path[], int path_len)
{
    for (int i = 0; i < path_len; i++)
        printf(" %d ", path[i]);
    printf("\n");
}
