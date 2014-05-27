#include <stdio.h>
#include <stdlib.h>

#define MAX  1000

typedef struct interval
{
    int start;
    int end;

}interval_t;

void merge_intervals(interval_t* array, int len)
{
    int combine[MAX] = {0};
    for (int i = 0; i < len; i++)
    {
        if (array[i].start == -1) continue;

        for (int j = array[i].start; j <= array[i].end; j++)
	   combine[j] = 1; 
    }

    int index = 0;
    for (int k = 0; k < MAX; k++)
    {
        while (combine[k] == 0 && k < MAX) k++;
	if (k < MAX)
	    array[index].start = k;
        while (combine[k] != 0 && k < MAX) k++;
	if (k < MAX)
	    array[index].end = k - 1;
	if (k < MAX)
	    index++;
    }

    //clear the remaining struct
    for(int i = index; i < len; i++)
    {
        array[i].start = 0;
	array[i].end = 0;
    }
}

void insert_intervals(interval_t* array, int len, interval_t target)
{
    array[len].start = target.start;
    array[len].end = target.end;
    merge_intervals(array, len + 1);
}

void test()
{
    interval_t array[5] = {};
    array[0].start = 1;
    array[0].end = 3;
    array[1].start = 2;
    array[1].end = 6;
    array[2].start = 8;
    array[2].end = 10;
    array[3].start = 15;
    array[3].end = 18;
    array[4].start = -1;
    array[4].end = -1;

    merge_intervals(array, 4);

    for (int i = 0; i < 4; i++)
        printf("[%d, %d],", array[i].start, array[i].end);

    printf("\n");

    interval_t target;
    target.start = 10;
    target.end = 15; 
    insert_intervals(array, 4, target);
    for (int i = 0; i < 4; i++)
        printf("[%d, %d],", array[i].start, array[i].end);

    printf("\n");
}

int main()
{
    test();
}
