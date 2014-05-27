/*
 *deallocates list's memory and sets its head pointer to NULL
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"

void delete_list_test();
void delete_list(node_t** list);

int main()
{
    delete_list_test();
}

void delete_list_test()
{
    node_t* my_list = build_simple_list();
    delete_list(&my_list);
    printf("Done\n");
}

void delete_list(node_t** list)
{
    while (*list!= NULL)
    {
        node_t* tmp = *list;
	//(*list)->next = (*list)->next->next;
	*list= (*list)->next;
	free(tmp);
    }
    *list = NULL;
}
