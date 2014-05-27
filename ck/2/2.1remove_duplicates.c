/*
 *write code to remove duplicates from an unsorted linked list
 *follow up:
 *How would you solve this problem if a temporay buffer is not allowed?
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"

void remove_duplicates_test();
void remove_duplicates(node_t* head);

int main()
{
    remove_duplicates_test();
}

void remove_duplicates_test()
{
    node_t* head = build_n_list(30, 100);
    print_list(head);
    remove_duplicates(head);
    print_list(head);
}

//1. can also use hash table
//2. use two pointers in this example
void remove_duplicates(node_t* head)
{
    if (head == NULL || head->next == NULL) return;
    node_t* pscan = head;
    
    while (head)
    {
	while (pscan->next)
	{
            if (head->data == pscan->next->data)
	    {
                pscan->next = pscan->next->next;
	    } else {
	        pscan = pscan->next;
	    }
	}
	head = head->next;
	pscan = head;
    }
}
