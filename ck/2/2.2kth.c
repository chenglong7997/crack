/*
 *implement an algorithm to find the kth to last element of a singly linked list
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

node_t* get_kth_last(node_t* head, int k);
void get_kth_last_test();
/*
int main()
{
    get_kth_last_test();
}
*/
void get_kth_last_test()
{
    node_t* head = build_n_list(46, 100);
    print_list(head);

    node_t* kth = get_kth_last(head, 7);

    if (kth)
        printf("%d\n", kth->data);
}

node_t* get_kth_last(node_t* head, int k)
{
    if (head == NULL) return NULL;
    node_t* fast = head;
    node_t* slow = head;

    while (fast != NULL && k > 1)
    {
        fast = fast->next;
	k--;
    }

    if (fast == NULL) assert(0);
    while (fast->next != NULL)
    {
        fast = fast->next;
	slow = slow->next;
    }
    return slow;
}
