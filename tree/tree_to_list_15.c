#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "insert.c"

void helper(node_t* root, node_t *& prev, node_t *& head)
{
    if (!root) return;
    helper(root->left, prev, head);

    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
	prev->right = root;
    }

    //to the circuar list
    head->left = root;
    root->right = head;

    prev = root;
    helper(root->right, prev, head);
}

node_t* tree_to_list(node_t* root)
{
    node_t* head = NULL;
    node_t* prev = NULL;
    helper(root, prev, head);
    return head;
}

void test()
{
    node_t* root = build_bst(30);

    node_t* head = tree_to_list(root);

    while (head != NULL)
    {
        printf("%d  ", head->data);
        head = head->right;
    }
    printf("\n");
}

int main()
{
    test();
}
