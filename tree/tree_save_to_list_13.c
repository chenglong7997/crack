/*
 *Do it for fun.
 *save the tree to list using the "next" pointer in each node
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "insert.c"

void tree_to_list(node_t* root);
void tree_to_list_test();

int main()
{
   tree_to_list_test();
}

void print_tree_list(node_t* root)
{
    node_t* head = NULL;
    if (root == NULL) return;

    while (root->left != NULL)
    {
        root = root->left;
    }

    head = root;
    while (head != NULL)
    {
        printf(" %d ", head->data);
	head = head->next;
    }
}

void tree_to_list_test()
{
    node_t* root = build_bst(30);
    tree_to_list(root);
    print_tree_list(root);

    printf("\n");

    root = build_n_tree(70, 0);
    tree_to_list(root);
    print_tree_list(root);
}

void tree_to_list(node_t* root)
{
    if (root == NULL)
        return;

    static node_t* pre = NULL;
    tree_to_list(root->right);
    
    root->next = pre;
    pre = root;

    tree_to_list(root->left);
}
