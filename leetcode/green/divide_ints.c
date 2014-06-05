/*
 *
 *binary search
 * */

#include <stdio.h>
#include <stdlib.h>


int divide(int dividend, int divisor)
{
    long a = abs(dividend);
    long b = abs(divisor);

    long ret = 0;

    while (a >= b)
    {
        long c = b;
	for (int i = 0; a >= c; ++i, c <<= 1)
	{
	    a -= c;
	    ret += 1 << i;
	}
    }

    return (dividend>>31) | (divisor>>31) ? (ret):(ret);
}

void test()
{
    printf("ret: %d\n", divide(1000, 3));
}

int main()
{
    test();
}
