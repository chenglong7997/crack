#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

/*this one is tricky*/

void insert_nth_test();
void insert_nth(node_t** list, int index, int value);

int main()
{
    insert_nth_test();
}

void insert_nth_test()
{
    node_t* head = NULL;
    insert_nth(&head, 0, 13);
    insert_nth(&head, 0, 1);
    insert_nth(&head, 1, 23);
    insert_nth(&head, 1, 4);
//    insert_nth(&head, 17, 40);

    print_list(head);
    //delete_list();
}

void insert_nth(node_t** list, int index, int value)
{
    assert(index >= 0);
    node_t* pre = *list;

    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = value;
   
    //handle *list == NULL or index == 0 cases 
    if (*list == NULL) assert(index == 0);

    if (index == 0)
    {
        new_node->next = *list;
        *list = new_node;
	return;
    }

    //handle *list != NULL && index != 0
    while (index > 1 && pre)
    {
	pre = pre->next;
	--index;
    }

    assert(pre); //if pre == NULL then index out of scope

    new_node->next = pre->next;
    pre->next = new_node;
}

