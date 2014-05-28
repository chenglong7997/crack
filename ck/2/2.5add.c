/*
 *You have two numbers represented by a linked list, where each node contails a single digit.
 *The digits are stored in reverse order. Write function that adds the two numbers and return
 *the sum as a linked list
 *
 * Follow up:
 * suppose the digits are stored in forward order, repeat the above problem
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

int len(node_t* head);
node_t* add_lists(node_t* left, node_t* right);
void append(node_t** head, int value);
void add_lists_test();
node_t* add_reverse_lists(node_t* left, node_t* right);

int main()
{
    add_lists_test();    
}

void add_lists_test()
{
    node_t* list1 = build_simple_list();
    node_t* list2 = build_simple_list();

    printf("test1\n");
    print_list(list1);
    print_list(list2);
    node_t* result = add_reverse_lists(list1, list2);
    print_list(result);

    printf("test2\n");
    list1 = build_n_list(4, 10);
    list2 = build_n_list(4, 10);
    print_list(list1);
    print_list(list2);
    result = add_reverse_lists(list1, list2);
    print_list(result);
    
    printf("test3\n");
    list1 = build_n_list(4, 10);
    list2 = build_n_list(5, 10);
    print_list(list1);
    print_list(list2);
    result = add_lists(list1, list2);
    print_list(result);
}

void push(node_t** head, int data)
{
    if (*head == NULL)
    {
        *head = new_node(data);
    } else {
        node_t* tmp  = new_node(data);
	tmp->next = *head;
	*head = tmp;
    }
}

//return the carry
int helper(node_t* left, node_t* right, node_t** head)
{
    if (!left || !right) return 0; 

    int carry = helper(left->next, right->next, head);
    int sum = carry + left->data + right->data;
    push(head, sum % 10);
    return sum / 10;
}

//1. reverse the list. 
//2. or use a stack to add from tail 
//3. change to int. 
node_t* add_reverse_lists(node_t* left, node_t* right)
{

    int left_len = len(left);
    int right_len = len(right);
    int diff = left_len - right_len;
    node_t* left_index = left;
    node_t* right_index = right;
    node_t* head = NULL;

    //fix the start index
    while (diff) 
    {
        if (diff > 0)
	{
	    append(&head, left->data);
            left_index = left_index->next;
	    diff--;
	} else {
	    append(&head, right->data);
	    right_index = right_index->next;
	    diff++;
	}
    }

    //
    int carry = helper(left, right, &head);

    if (carry)
        append(&head, carry);

    return head;
}


node_t* add_lists(node_t* left, node_t* right)
{
    //len
    int left_len = len(left);
    int right_len = len(right);
    int diff = left_len - right_len;
    node_t* left_index = left;
    node_t* right_index = right;
    node_t* result = NULL;
    int count = 0;
    int sum = 0;

    //fix the start index
    while (diff) 
    {
        if (diff > 0)
	{
	    append(&result, left->data);
            left_index = left_index->next;
	    diff--;
	} else {
	    append(&result, right->data);
	    right_index = right_index->next;
	    diff++;
	}
    }
    
    /*add lists*/
    while (left_index && right_index)
    {
        sum = left_index->data + right_index->data + count;
        append(&result, sum % 10);
	count = sum / 10;
        left_index = left_index->next;
	right_index = right_index->next;
    }
    if (count > 0)
        append(&result, count);
    return result;
}

int len(node_t* head)
{
    int length = 0;
    while (head != NULL)
    {
        head = head->next;
	length++;
    }
    return length;
}

void append(node_t** head, int value)
{
    static node_t* tail = NULL;
    if (*head == NULL)
    {
        *head = new_node(value);
        tail = *head;
    } else {
        tail->next = new_node(value);
	tail = tail->next;
    }
}

