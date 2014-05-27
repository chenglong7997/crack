#include <stdio.h>
#include <stdlib.h>

void connect(node_t* root)
{
    if (root == NULL) return;

    if (root->left)
    {
        root->left->next = root->right;
    }
    if (root->right)
    {
        root->right->next = root->next? root->next->left: NULL;
    }

    connect(root->left);
    connect(root->right)
}


int main()
{

}
