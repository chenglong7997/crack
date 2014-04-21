#include <stdio.h>
#include <stdlib.h>

void malloc_test(int n);

int main()
{
    malloc_test(5);
}


void malloc_test(int n)
{
    int* p = (int*)malloc(sizeof(int) * n);
    return;
}
