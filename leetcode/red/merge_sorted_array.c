/*
 *Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *Note:
 *You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */

#include <stdio.h>
#include <stdlib.h>

//merge from back to front
void merge_array(int* array_a, int m, int* array_b, int n)
{
    int index_a = m - 1;
    int index_b = n - 1;

    for (int i = m + n - 1; i >= 0; i--)
    {
        //only a left or a[] > b[]
        if ( (index_b == -1 && index_a >= 0) || 
             (index_a >= 0 && index_b >= 0 && array_a[index_a] >= array_b[index_b]) )
	{
	    array_a[i] = array_a[index_a];
	    index_a--;
	}
	else if ((index_a == -1 && index_b >= 0) ||
                 (index_a >= 0 && index_b >= 0 && array_a[index_a] < array_b[index_b]))
	{
	    array_a[i] = array_b[index_b];
	    index_b--;
	}
    }
}

void test()
{
    int array_a[10] = {3, 5, 7, 9, 55, 0, 0, 0, 0};
    int array_b[4] = {1, 2, 10, 100};
    merge_array(array_a, 5, array_b, 4);
    for (int i = 0; i < 10; i++)
        printf(" %d ", array_a[i]);
    printf("\n");
}

int main()
{
    test();
}
