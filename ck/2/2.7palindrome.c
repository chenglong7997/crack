/*
 *implement a function to check if a linked list is a palindrome
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void is_palindrome_test();
int is_palindrome(node_t* head);
node_t* reverse_list(node_t* head);
int is_same_list(node_t* left, node_t* right);

int main()
{
    is_palindrome_test();
}

void is_palindrome_test()
{
    node_t* head = build_simple_list();
    printf("%d\n", is_palindrome(head));

    head = new_node(1);
    node_t* tmp1 = new_node(2);
    node_t* tmp2 = new_node(2);
    node_t* tmp3 = new_node(1);
    tmp1->next = tmp2;
    tmp2->next = tmp3;
    head->next = tmp1;
    printf("%d\n", is_palindrome(head));
}

int is_palindrome(node_t* head)
{
    if (head == NULL) return 1;

    node_t* reverse = reverse_list(head);
    return is_same_list(reverse, head);
}

node_t* reverse_list(node_t* head)
{
    node_t* result = NULL;
    node_t* tmp = NULL;

    while (head != NULL)
    {
        tmp = new_node(head->data);
        tmp->next = result;
	result = tmp;
        head = head->next;
    }
    return result;
}

int is_same_list(node_t* left, node_t* right)
{
    while (left && right)
    {
        if (left->data == right->data)
        {
            left = left->next;
	    right = right->next;
	} else
            return 0;
    }

    if ((left == NULL && right != NULL) || (left != NULL && right == NULL)) return 0;
    return 1;
}
