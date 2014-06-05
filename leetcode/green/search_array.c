/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int do_search(int a[], int start, int end, int target)
{
    if (start > end) return -1;
    int mid = (start + end) / 2;

    if (a[mid] == target)
        return mid;
    else if (a[mid] > a[start])
    {
	if (a[mid] > target && target > a[start])
	    return do_search(a, start, mid - 1, target);
	else
	    return do_search(a, mid + 1, end, target);
    }
    else
    {
	if (a[mid] < target && target < a[end])
	    return do_search(a, mid + 1, end, target);
	else
            return do_search(a, start, mid - 1, target);	
    }
}

int search(int a[], int n, int target)
{
    if (n == 0) return -1;

    int start = 0;
    int end = n - 1;
    return do_search(a, start, end, target); 
}

void test()
{
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    printf("index: %d\n", search(a, 7, 6));
    printf("index: %d\n", search(a, 7, 3));
}

int main()
{
    test();
}

