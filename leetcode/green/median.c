#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a > b? b : a;
}

double do_find_median_sorted_arrays(int a[], int m, int b[], int n, int k)
{
    if (m > n) return do_find_median_sorted_arrays(b, n, a, m, k);

    if (m == 0) return b[k - 1];
    if (k == 1) return min(a[0], b[0]);

    int pa = min(k/2, m);
    int pb = k - pa;

    if (a[pa - 1] <= b[pb - 1]) return do_find_median_sorted_arrays(a+pa, m-pa, b, n, k-pa);
    else return do_find_median_sorted_arrays(a, m, b+pb, n-pb, k-pb);
}


double find_median_sorted_arrays(int a[], int m, int b[], int n)
{
    int total = m + n;
    if (total % 2 == 1)
	    return do_find_median_sorted_arrays(a,m,b,n,total/2+1);
    else
	    return (do_find_median_sorted_arrays(a,m,b,n,total/2) + 
		    do_find_median_sorted_arrays(a,m,b,n,total/2+1))/2;
}

void test()
{
    int a[] = {1, 3, 5, 6, 9};
    int b[] = {2, 4, 6, 8};
    printf("median %f\n", find_median_sorted_arrays(a, 5, b, 4));
}

int main()
{
    test();
}
