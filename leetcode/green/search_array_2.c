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
	if (a[mid] > target && target >= a[start])
	    return do_search(a, start, mid - 1, target);
	else
	    return do_search(a, mid + 1, end, target);
    }
    else if (a[mid] < a[start])
    {
	if (a[mid] < target && target <= a[end])
	    return do_search(a, mid + 1, end, target);
	else
            return do_search(a, start, mid - 1, target);	
    }
    else return do_search(a, start + 1, end, target);
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
    int a[] = {3, 1, 2, 3, 3, 3, 3};
    printf("index: %d\n", search(a, 7, 1));
    printf("index: %d\n", search(a, 7, 2));
}

int main()
{
    test();
}

