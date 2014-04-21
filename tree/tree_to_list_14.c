#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "insert.c"

void tree_to_list_test();
void tree_to_list(node_t* root);
node_t* search_last(node_t* root);
node_t* search_first(node_t* root);

int main()
{
    tree_to_list_test();
}

void tree_to_list_test()
{
    node_t* root = build_bst(30);
    node_t* head = search_first(root);
    node_t* tail = search_last(root);
    tree_to_list(root);
    
    while (head)
    {
        printf(" %d ", head->data);
        head = head->right;
    }
    printf("\n");
    
    printf("Reverse\n");
    while (tail)
    {
        printf(" %d ", tail->data);
        tail = tail->left;
    }
    printf("\n");
}

void tree_to_list(node_t* root)
{
    if (root == NULL)
        return;

    tree_to_list(root->left);
    tree_to_list(root->right);

    node_t* last = search_last(root->left);
    node_t* first = search_first(root->right);

    if (last)
        last->right = root;
    root->left = last;

    if (first)
        first->left = root;
    root->right = first;
}

node_t* search_last(node_t* root)
{
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

node_t* search_first(node_t* root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
