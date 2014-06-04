/*
 *Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 *You may assume that each input would have exactly one solution.`
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//O(n ^ 2)
void two_sum(int* array, int len, int sum)
{
    if (array == NULL) return;

    int remain = 0;
    for (int i = 0; i < len; i++)
    {
        remain = sum - array[i];
        for (int j = 0; j < len; j++)
	{
	    if (array[j] == remain)
            {
		    printf("index %d, index %d\n", i + 1, j + 1);
		    return;
	    }
	}
    }
}

//sort -->O(nlogn)
//hash -->O(n) can return index easier

void test()
{
    int array[5] = {2, 7, 5, 6, 9};
    two_sum(array, 5, 9);
}

int main()
{
    test();
}
