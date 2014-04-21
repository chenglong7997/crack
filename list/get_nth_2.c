#include <stdio.h>
#include "build.h"

void get_nth_test();
int get_nth(node_t* list, int index);

int main()
{
    get_nth_test();
}

void get_nth_test()
{
    node_t* my_list = build_simple_list();
    int value = get_nth(my_list, 2);
    printf("the 2 value is %d\n", value);
    value = get_nth(my_list, 1);
    printf("the 1 value is %d\n", value);
}

int get_nth(node_t* list, int index)
{
    if (index < 0)
    {
        printf("index should be not negative\n");
        exit(1);
    }

    while(list != NULL)
    {
        if (index == 0)
	    return list->data;
        --index;	
        list = list->next;
    }

    if (list == NULL)
    {
        printf("we donot have so many elements\n");
	exit(1);
    }
    //should never exe
    return -1;
    /*perfer assert(0) / exit(1);*/
}

/*
 *if (==)
 */
