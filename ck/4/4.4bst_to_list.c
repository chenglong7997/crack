#include <iostream>
#include <queue>
#include "build.h"

void test();
void push (node_t** list, node_t* node);
node_t* bfs_to_list(node_t* root);

int main()
{
    test();
}

void test()
{
    node_t* root = build_n_tree(15, 0);
    node_t* list_head = bfs_to_list(root);

    while (list_head != NULL)
    {
        node_t* right_list = list_head->right;
        while (right_list)
	{
	    printf(" %d ", right_list->data);
	    right_list = right_list->next;
	}
	printf("\n");
	list_head = list_head->next;
    }
}

void push (node_t** list, node_t* node)
{
    node->next = *list;
    *list = node;
}

/*
 *   NULL
 *     ^
 *     |
 *     |
 *   next
 *     ^
 *     |
 *   list->right   --> .......
 *     ^
 *     |
 *     |
 *
 *   next
 *     ^
 *     |
 *   list->right   --> node4->next --> node5->next --> NULL
 *     ^
 *     |
 *     |
 *
 *    next
 *     ^
 *     |
 * list_head->right --> node1->next --> node2->next --> node3->next --> NULL
 *   
 * 
 * */

node_t* bfs_to_list(node_t* root)
{
    if (root == NULL) return NULL;

    int cur_level_nodes = 0;
    int next_level_nodes = 0;
    node_t* list_head = new_node(0);;
    node_t* tail = list_head;

    std::queue<node_t*> myqueue;
    myqueue.push(root);
    ++cur_level_nodes;

    while (!myqueue.empty())
    {
        node_t* cur = myqueue.front();
	myqueue.pop();
	//printf(" %d ", cur->data);
        push(&(tail->right), new_node(cur->data));

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
            //printf("\n");
            tail->next = new_node(0);
	    tail = tail->next;
	    cur_level_nodes = next_level_nodes;
	    next_level_nodes = 0;
	}
    }
    return list_head;
}
