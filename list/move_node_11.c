/*
 *takes two lists, removes the front node the the second list and pushs in to 
 *the front of the first.
 * */

#include <stdio.h>
#include <stdlib.h>
#include "build.h"
#include <assert.h>

void move_node_test();
void move_node(node_t** dst_ref, node_t** src_ref);
/*
int main()
{
    move_node_test();
}
*/
void move_node_test()
{
    node_t* dst_list = build_n_list(3);
    node_t* src_list = build_n_list(5);
    print_list(dst_list);
    print_list(src_list);
    
    move_node(&dst_list, &src_list);
    
    print_list(dst_list);
    print_list(src_list);
}

void move_node(node_t** dst_ref, node_t** src_ref)
{
    if (*src_ref == NULL)
        return;
    node_t* work = *src_ref;
    *src_ref = (*src_ref)->next;
    work->next = *dst_ref;
    *dst_ref = work;
}
