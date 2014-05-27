/*
 *Find the first common ancestor of two nodes in a binary tree
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bfs.cc"
#include "build.h"

int inorder(node_t* root, node_t* left, node_t* right);

node_t* find_common_ancestor(node_t* root, node_t* left, node_t* right)
{
    if (root == NULL || left == NULL || right == NULL) return NULL;
    if (root->data == left->data || root->data == right->data) return root;

    int l = inorder(root->left, left, right);
    // they are in root->left subtree
    if (l == 2) return find_common_ancestor(root->left, left, right);
    // one in root->left subtree, another should be in root->right subtree
    if (l == 1) return root;
    // they are in root->right subtree
    if (l == 0) return find_common_ancestor(root->right, left, right);
    return NULL;    
}

int inorder(node_t* root, node_t* left, node_t* right)
{
    if (root == NULL || left == NULL || right == NULL) return 0;
    int ret = 0;
    if (root->data == left->data || root->data == right->data) ret++;
    ret += inorder(root->left, left, right);
    ret += inorder(root->right, left, right);
    
    return ret;
}

/*
int inorder(node_t* root, node_t* target);

node_t* find_common_ancestor(node_t* root, node_t* left, node_t* right)
{
    if (root == NULL || left == NULL || right == NULL) return NULL;
    if (root->data == left->data || root->data == right->data) return root;
   
    int left_in_left = inorder(root->left, left);
    int right_in_left = inorder(root->left, right);
    int left_in_right = inorder(root->right, left);
    int right_in_right = inorder(root->right, right);

    if ((left_in_left && right_in_right ) ||
        (left_in_right && right_in_left ))
        return root;
    else if (left_in_left && right_in_left)
	    return find_common_ancestor(root->left, left, right);
    else if (left_in_right && right_in_right)
	    return find_common_ancestor(root->right, left, right);
    else
        assert(0);
}

int inorder(node_t* root, node_t* target)
{
    if (root == NULL || target == NULL) return 0;

    int ret = 0;
    if (root->data == target->data)
        return 1;
    
    ret = inorder(root->left, target);
    if (ret == 1) return 1;
    ret = inorder(root->right, target);
    if (ret == 1) return 1;

    return 0;
}
*/

void test()
{
    node_t* root = build_n_tree(30, 0);
    bfs(root);

    node_t* ret = NULL;
    ret = find_common_ancestor(root, root->left->right, root->left->left);
    if (ret) printf("%d\n", ret->data);
    
    ret = find_common_ancestor(root, root->right->right, root->right->left);
    if (ret) printf("%d\n", ret->data);
    
    ret = find_common_ancestor(root, root->left->right, root->right->left);
    if (ret) printf("%d\n", ret->data);
}

int main()
{
    test();
}
