/*
 *count the number of times a given int occurs in a list
 * */

#include <stdio.h>
#include "build.h"

void count_test();
int count(node_t* list, int value);

int main()
{
    count_test();
}

void count_test()
{
    node_t* my_list = build_simple_list();
    int counter = count(my_list, 2);
    printf("count is %d\n", counter);
}

int count(node_t* list, int value)
{
    int counter = 0;
    while (list != NULL)
    {
        if (list->data == value)
	    ++counter;
	list = list->next;
    }
    return counter;
}

/*
 *variable and function name should not same
 *typedef struct
 *do not forget to iterate list
 */
