#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "bfs.cc"


void double_tree_test();
void double_tree(node_t* root);

int main()
{
    double_tree_test();
}

void double_tree_test()
{
    node_t* root = build123();
    double_tree(root);
    bfs(root);
}

void double_tree(node_t* root)
{
    if (root == NULL)
        return;
    else
    {
        node_t* pnew = new_node(root->data);
	pnew->left = root->left;
	root->left = pnew;
	double_tree(root->left->left);
	double_tree(root->right);
    }

}


