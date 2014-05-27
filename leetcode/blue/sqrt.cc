#include <stdio.h>
#include <stdlib.h>

//binary search from 0 - (n/2 + 1)
int sqrt(int x)
{
    int i = 0;
    int j = x / 2 + 1;
    int mid = 0;

    while (i <= j)
    {
        mid = (i + j) / 2;
	if (x < mid * mid) j = mid - 1;
	else if (x > mid * mid) i = mid + 1;
	else return mid;
    }
    return -1;
}


void test()
{
    printf("sqrt(100) %d\n", sqrt(100));
    printf("sqrt(25) %d\n", sqrt(25));
    printf("sqrt(40) %d\n", sqrt(40));
}

int main()
{
    test();
}
