#include <iostream>
#include <queue>
#include "build.h"

#ifndef BFS_CC
#define BFS_CC

#define SPACES 100

void bfs(node_t* root);
/*
int main()
{
    node_t* root = build_n_tree(15, 0);
    bfs(root);

    for (int i = 0; i < 5; i++)
        printf("\n");

    root = build_n_tree(15, 1);
    bfs(root);

    for (int i = 0; i < 5; i++)
        printf("\n");
    root = build123();
    bfs(root);
}
*/
void bfs(node_t* root)
{
    int cur_level_nodes = 0;
    int next_level_nodes = 0;
    std::queue<node_t*> myqueue;
    myqueue.push(root);
    ++cur_level_nodes;
    int level = 1;

    while (!myqueue.empty())
    {
        node_t* cur = myqueue.front();
	myqueue.pop();
	printf("%*d", SPACES / (1 << level), cur->data);
        printf("%*c", SPACES / (1 << level), ' ');

	if (cur->left)
	{
            myqueue.push(cur->left);
            ++next_level_nodes;
	}
	if (cur->right)
	{
            myqueue.push(cur->right);
            ++next_level_nodes;
	}
        
	if (--cur_level_nodes == 0)
	{
	    ++level;
            printf("\n");
            cur_level_nodes = next_level_nodes;
	    next_level_nodes = 0;
	}
    }
}

#endif
