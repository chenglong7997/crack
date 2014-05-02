#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "build.h"
#include "bfs.cc"

int get_height(node_t* root)
{
    if (root == NULL) return 0;

    return std::max(get_height(root->left),get_height(root->right)) + 1;
}

int is_balanced(node_t* root)
{
    if (root == NULL) return 1;

    if (abs(get_height(root->left) - get_height(root->right)) > 1)
        return 0;
    else
        return is_balanced(root->left) && is_balanced(root->right);
}

int get_height_balanced(node_t* root)
{
    if (root == NULL) return 0;

    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    
    if (left_height == -1 || right_height == -1) return -1;

    if (abs(left_height - right_height) > 1)
        return -1;

    return std::max(left_height, right_height) + 1;
}

void test()
{
    node_t* root = build_n_tree(30, 0);
    bfs(root);
    node_t* root2 = build_n_tree(50, 0);
    bfs(root2);
    node_t* root3 = build_n_tree(90, 0);
    bfs(root3);
    node_t* root4 = build_n_tree(1000, 0);
    bfs(root4);
    node_t* root5 = build123();
    bfs(root5);
    
    printf("balanced? %d\n", is_balanced(root));
    printf("balanced? %d\n", get_height_balanced(root));
    
    printf("balanced? %d\n", is_balanced(root2));
    printf("balanced? %d\n", get_height_balanced(root2));
    
    printf("balanced? %d\n", is_balanced(root3));
    printf("balanced? %d\n", get_height_balanced(root3));
    
    printf("balanced? %d\n", is_balanced(root4));
    printf("balanced? %d\n", get_height_balanced(root4));
    
    printf("balanced? %d\n", is_balanced(root5));
    printf("balanced? %d\n", get_height_balanced(root5));
}

/*
int max(int left, int right)
{
    return left > right? left: right;
}
*/

int main()
{
    test();
}


