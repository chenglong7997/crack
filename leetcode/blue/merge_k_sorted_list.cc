#include <iostream>
#include <vector>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node_t;

vector<node_t*>* build_lists()
{
    node_t* head1 = (node_t*)malloc(sizeof(node_t));
    node_t* head2 = (node_t*)malloc(sizeof(node_t));
    node_t* head3 = (node_t*)malloc(sizeof(node_t));

    head1->data = 1;
    head2->data = 2;
    head3->data = 3;

    node_t* tail1 = head1;
    node_t* tail2 = head2;
    node_t* tail3 = head3;
    
    int len1 = 10;
    int len2 = 20;
    int len3 = 30;
    
    while (len1-- != 0)
    {
        tail1->next = (node_t*)malloc(sizeof(node_t));
	tail1->next->data = tail1->data + 3;
        tail1 = tail1->next;
	tail1->next = NULL;
    }
    
    while (len2-- != 0)
    {
        tail2->next = (node_t*)malloc(sizeof(node_t));
	tail2->next->data = tail2->data + 3;
        tail2 = tail2->next;
	tail2->next = NULL;
    }
    
    while (len3-- != 0)
    {
        tail3->next = (node_t*)malloc(sizeof(node_t));
	tail3->next->data = tail3->data + 3;
        tail3 = tail3->next;
	tail3->next = NULL;
    }

    vector<node_t*> vn;
    vn.push_back(head1);
    vn.push_back(head2);
    vn.push_back(head3);
    
    return vn;
}

node_t *merge_k_lists(vector<node_t*> &lists)
{
    //sort the vector
    //pick the smallest element
    //sort again
}

void test()
{
    vector<node_t*> vn = build_test();
    node_t* total = merge_k_lists(vn);
}

int main()
{
    test();
}
