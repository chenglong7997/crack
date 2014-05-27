#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int clambing_stairs(int n)
{
    if (n < 0) assert(0);
    if (n == 1 || n == 0) return 1;

    return clambing_stairs(n - 1) + clambing_stairs(n - 2);
}

void test()
{
    printf("10 %d\n", clambing_stairs(10));
    printf("5 %d\n", clambing_stairs(5));
    printf("30 %d\n", clambing_stairs(30));
    printf("40 %d\n", clambing_stairs(40));
}

int main()
{
    test();
}
