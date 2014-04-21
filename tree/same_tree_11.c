#include <stdio.h>
#include <stdlib.h>
#include "build.h"

void same_tree_test();
int same_tree(node_t* a, node_t* b);

int main()
{
    same_tree_test();
}

void same_tree_test()
{
    node_t* a = build123();
    node_t* b = build_n_tree(10, 0);
    printf("%d\n", same_tree(a, b));
}

int same_tree(node_t* a, node_t* b)
{
    if (a == NULL && b == NULL)
        return 1;
    else if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
        return 0;
    else
    {
        if (a->data != b->data)
            return 0;
	else
	    return same_tree(a->left, b->left) && same_tree(a->right, b->right);
    }
}
