/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 *
 * */

#include <stdio.h>
#include <stdlib.h>


int remove_dup(int a[], int n)
{
    if (n == 0 || n == 1) return n;

    int i = 0;

    for (int j = 1; j < n; j++)
    {
        if (a[j] != a[i])
	{
	    a[++i] = a[j];
	}
    }
    return ++i;
}


void test()
{
    int a[] = {1,1,2};
    printf("%d\n", remove_dup(a, 3));
}

int main()
{
    test();
}
