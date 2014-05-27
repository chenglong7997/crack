/*
 *decide if T2 is a subtree of T1
 *
 * A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of
 * n is identical to T2. That is, if you cut off the tree at node n, the two trees would
 * be identical
 * similar question: T2 contains T1 (lc)
 * */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "build.h"
#include "bfs.cc"

int is_same_tree(node_t* t1, node_t* t2)
{
    if (t1 == t2 && t1 == NULL) return 1;
    if ((t1 && !t2) || (!t1 && t2)) return 0;
    if (t1->data != t2->data) return 0;

    return is_same_tree(t1->left, t2->left) && is_same_tree(t1->right, t2->right);
}

int is_subtree(node_t* t1, node_t* t2)
{
    if (t1 == NULL || t2 == NULL) return 1;
    int ret = 0;
    if (t1->data == t2->data) ret = is_same_tree(t1, t2);
    if (ret) return ret;
    
    ret = is_subtree(t1->left, t2);
    if (ret) return ret;
    
    ret = is_subtree(t1->right, t2);
    if (ret) return ret;
    
    return 0;
}

void test()
{
    node_t* t1 = build123();
    node_t* t2 = new_node(4);
    t2->right = new_node(5);

    printf("%d\n", is_subtree(t1, t2));
}

int main()
{
    test();
}
