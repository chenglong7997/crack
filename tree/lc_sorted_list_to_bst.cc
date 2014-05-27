#include <iostream>

node_t* sorted2bst(node_t* head)
{
    if (!head) return NULL;
    node_t* p = head;
    int counter = 0;

    while (p)
    {
        ++counter;
        p = p->next;
    }
    return helper(head, 0, counter - 1);
}

node_t* helper(node_t* head, int start, int end)
{
    if (start > end) return NULL;
    int mid = (start + end) / 2;

    node_t* left = helper(head, start, mid - 1)
    node_t* parent = new_node(head->data);
    parent->left = left;
    head = head->next;

    node_t* right = helper(head, mid + 1, end);
    parent->right = right;

    return parent;
}

int main()
{

}
