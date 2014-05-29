#include <stdio.h>
#include <stdlib.h>

void helper(node_t* root, node_t* n1, node_t* n2, node_t* prev)
{
    if (root == NULL) return;
    helper(root->left, n1, n2, prev);
    if (prev && prev->val > root->val)
    {
        if (!n1)
            n1 = prev;
	else
            n2 = root;
    }
    prev = root;
    helper(root->right, n1, n2, prev);
}

void recover_tree(node_t* root)
{
    node_t* n1 = NULL;
    node_t* n2 = NULL;
    node_t* prev = NULL;

    helper(root, n1, n2, prev);

    if (n1 && n2)
	    swap(n1->val, n2->val);
}

int main()
{

}


