/*
 *print inorder
 * */

#include <stdio.h>
#include <stdlib.h>
#include "insert.c"

void print_inorder_tree_test();
void print_inorder_tree(node_t* root);
void print_inorder_reverse_tree(node_t* root);

int main()
{
    print_inorder_tree_test();
}

void print_inorder_tree_test()
{
    node_t* root = build_bst(30);
    print_inorder_tree(root);
    printf("\n");
    
    print_inorder_reverse_tree(root);
    printf("\n");
}

void print_inorder_tree(node_t* root)
{
    if (root == NULL)
        return;
    else {
        print_inorder_tree(root->left);
        printf(" %d ", root->data);
	print_inorder_tree(root->right);
    }
}

void print_inorder_reverse_tree(node_t* root)
{
    if (root == NULL)
        return;
    else {
        print_inorder_reverse_tree(root->right);
        printf(" %d ", root->data);
	print_inorder_reverse_tree(root->left);
    }
}
