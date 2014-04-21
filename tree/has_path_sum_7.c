#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include "bfs.cc"

void has_path_sum_test();
int has_path_sum(node_t* root, int sum);

int main()
{
    has_path_sum_test();
}

void has_path_sum_test()
{
    node_t* root = build123();
    bfs(root);
    printf("%d\n", has_path_sum(root, 5));
}

int has_path_sum(node_t* root, int sum)
{
    if (root != NULL)
        sum -= root->data;
    else
        return 0;

    if (sum == 0 && root->left == 0 && root->right == 0)
        return 1;
    return has_path_sum(root->left, sum) || has_path_sum(root->right, sum);
}
