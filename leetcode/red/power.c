#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//remember add the base case
int power(int x, int n)
{
    if (n == 1) return x;
    if (n == 0) return 1;

    if ((n / 2 + n / 2) == n)
        return power(x, n / 2) * power(x, n / 2);
    else if ((n / 2 + n / 2 + 1) == n)
        return power(x, n / 2) * power(x, n / 2) * x;
    else
        assert(0);
}

double power2(double x, int n)
{
    if (n == 1) return x;
    if (n == 0) return 1;

    double ans = 1;
    double tmp = 0;
    int flag = 0;

    if (n % 2 != 0)
        ans *= x;

    if (n < 0) 
    {
	tmp =  power(x, -n / 2);
        flag = 1;
    }
    else tmp = power(x, n / 2);

    return flag? (double)(1.0 / (tmp * tmp * ans)) : tmp * tmp * ans;
}

void test()
{
    printf("pow(2, 7) = 128 %d\n", power(2, 7));
    printf("pow(2, 8) = 256 %d\n", power(2, 8));
    
    printf("pow(2, 7) = 128 %f\n", power2(2, 7));
    printf("pow(2, 8) = 256 %f\n", power2(2, 8));
    printf("pow(2, -8) = 1/256 %lf\n", power2(2.0, -8));
}


int main()
{
    test();
}
