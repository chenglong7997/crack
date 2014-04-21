#include <stdio.h>
#include <stdlib.h>
#include "bfs.cc"

void insert_test();
node_t* insert(node_t* root, int data);
/*
int main()
{
    insert_test();
}
*/
void insert_test()
{
    node_t* root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 8);
    bfs(root);
}

node_t* insert(node_t* root, int data)
{
    node_t* pnew = new_node(data);
    if (root == NULL)
        return  pnew;
    else if (root->data < data)
        root->right = insert(root->right, data);
    else
        root->left = insert(root->left, data);
    return root;
}

node_t* build_bst(int n)
{
    node_t* root = NULL;
    for (int i = 0; i < n; ++i)
    {
        root = insert(root, (rand() % 100));
    }
    return root;
}
