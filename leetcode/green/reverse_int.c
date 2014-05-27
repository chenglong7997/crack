#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
    int negative = 0;
    if (x < 0)
    {
        negative  = 1;
	x = -x;
    }

    int reminder = 0;
    int div = 0;
    int ans = 0;
    
    while (x)
    {
        reminder = x % 10;
	div = x / 10;
	ans = 10 * ans + reminder;
	x = div;
    }

    //overflow
    if (ans < 0) return -1;
    //return ans;
    return negative ? -ans : ans;
}


void test()
{
    printf("123 reverse : %d\n", reverse(123));
    printf("-123 reverse : %d\n", reverse(-123));
}

int main()
{
    test();
}
