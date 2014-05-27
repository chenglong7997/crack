#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef BUILD_H
#define BUILD_H

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
}node_t;

node_t* new_node(int data)
{
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->next = NULL;
    return tmp;
}

void print_tree(node_t* root)
{
    if (root == NULL)
        return;
    printf(" %d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
    printf("\n");
}

node_t* build_n_tree(int n, int flag)
{
    int i = 0;
    node_t* array = (node_t*)malloc(sizeof(node_t) * n);
    for (i = 0; i < n; i++)
    {
	if (flag == 0) //rand tree
            array[i].data = rand() % 10;
	else //not BST tree
	    array[i].data = i;

        if ((2 * i + 1) < n)
            array[i].left = array + 2 * i + 1;
	else
            array[i].left= NULL;
	
	if ((2 * i + 2) < n)
	    array[i].right = array + 2 * i + 2;
        else
            array[i].right = NULL;
    }
    return array;
}

node_t* build123()
{
    node_t* first = (node_t*)malloc(sizeof(node_t));
    node_t* second = (node_t*)malloc(sizeof(node_t));
    node_t* third = (node_t*)malloc(sizeof(node_t));
    node_t* fourth = (node_t*)malloc(sizeof(node_t));

    first->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;

    first->left = second;
    first->right = third;

    second->left = fourth;
    second->right = NULL;
    third->left = NULL;
    third->right = NULL;
    fourth->left = NULL;
    fourth->right = NULL;

    return first;
}

#endif
