#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "insert.c"

void is_bst_fast_test();
int is_bst_fast(node_t* root, int min, int max);
int is_bst_inorder(node_t* root);

int main()
{
    is_bst_fast_test();
}

void is_bst_fast_test()
{
    node_t* root = build_bst(30);
    printf("%d\n", is_bst_fast(root, INT_MIN, INT_MAX));
    root = build_n_tree(70, 0);
    printf("%d\n", is_bst_fast(root, INT_MIN, INT_MAX));
    
    root = build_bst(70);
    printf("%d\n", is_bst_inorder(root));
    root = build_n_tree(70, 0);
    printf("%d\n", is_bst_inorder(root));
}

int is_bst_fast(node_t* root, int min, int max)
{
    if (root == NULL)
        return 1;
    return (root->data <= max) && (root->data > min) && is_bst_fast(root->left, min, root->data) && is_bst_fast(root->right, root->data, max);
}

int is_bst_inorder(node_t* root)
{
    if (root == NULL)
        return 1;

    static int pre = INT_MIN;

    int left = is_bst_inorder(root->left);
    
    if (root->data >= pre)
        pre = root->data;
    else
        return 0;

    int right = is_bst_inorder(root->right);

    return left && right;
}
