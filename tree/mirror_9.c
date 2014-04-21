#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "bfs.cc"


void mirror_test();
void mirror(node_t* root);

int main()
{
    mirror_test();
}

void mirror_test()
{
    node_t* root = build123();
    bfs(root);
    mirror(root);
    bfs(root);
}

void mirror(node_t* root)
{
    node_t* tmp = NULL;
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    else
    {
        mirror(root->left);
        mirror(root->right);
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
    }
}
