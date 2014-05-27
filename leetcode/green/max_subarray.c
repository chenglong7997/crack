#include <stdio.h>
#include <stdlib.h>

int max_sub(int a[], int n)
{
    if (n <= 0) return 0;
    int sum = 0;
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
	if (sum <= 0)
	{
	    sum = 0;
	    continue;
	}
        if (sum > max)
            max = sum;
    }

    return max;
}

void test()
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("max = %d\n", max_sub(a, 9));
}

int main()
{
    test();
}
