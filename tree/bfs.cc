#include <iostream>
#include <queue>
#include "build.h"

#ifndef BFS_CC
#define BFS_CC

void bfs(node_t* root);
/*
int main()
{
    node_t* root = build_n_tree(15, 0);
    bfs(root);

    printf("\n");

    root = build_n_tree(15, 1);
    bfs(root);
}
*/
void bfs(node_t* root)
{
    std::queue<node_t*> myqueue;
    myqueue.push(root);
    while (!myqueue.empty())
    {
        node_t* cur = myqueue.front();
	myqueue.pop();
	printf(" %d ", cur->data);

	if (cur->left)
            myqueue.push(cur->left);
	if (cur->right)
            myqueue.push(cur->right);
    }
}

#endif
