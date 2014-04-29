#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "3.2min_stack.c"

typedef struct head_array_node{
    node_t* head;
    int flag;
    int sum;
}head_array_node_t;

#define THRESHOLD 10 

void set_stack_test();
void set_stack_push(head_array_node_t* array, int len, int value);
int set_stack_pop(head_array_node_t*  array, int len);
int pop_at(head_array_node_t* array, int len, int index);

int main()
{
    set_stack_test();
}

void set_stack_test()
{
    head_array_node_t array[100] = {0};

    int i = 25;
    while (i-- > 0)
        set_stack_push(array, 100, i);
   
    printf("pop at 0 %d\n", pop_at(array, 100, 0)); 
    printf("pop at 1 %d\n", pop_at(array, 100, 1)); 

    int j = 23;
    while(j--)
        printf(" %d ", set_stack_pop(array, 100));
   
    printf("\n");
}

int pop_at(head_array_node_t* array, int len, int index)
{
    if (index > len) assert(0);
    int tmp;
    tmp = pop(&(array[index].head));
    if (array[index].sum-- < THRESHOLD) array[index].flag = 0;
    return tmp;
}

void set_stack_push(head_array_node_t* array, int len, int value)
{
    int i = 0;
    for (; i < len; i++)
    {
        if (array[i].flag == 0)
            break;
    }

    if (i == len) assert(0);

    push(&(array[i].head), value);
    if (++array[i].sum > THRESHOLD)
        array[i].flag = 1;
}

int set_stack_pop(head_array_node_t* array, int len)
{
    int i = 0;
    if (array[0].sum == 0) assert(0);

    int tmp = 0;
    for (; i < len; i++)
    {
        if (array[i].sum == 0) break;
    }
    i--;
    tmp = pop(&(array[i].head));
    array[i].sum--;
    if (array[i].sum < THRESHOLD) array[i].flag = 0;
   
    return tmp;
}
