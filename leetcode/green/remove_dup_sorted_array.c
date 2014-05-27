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
