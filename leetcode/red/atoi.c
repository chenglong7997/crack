#include <stdio.h>
#include <assert.h>

int atoi(char* str)
{
    if (str == NULL) assert(0);
    int is_negative = 0;
    int ret = 0;

    if (*str == '-')
    {
        is_negative = 1;
        str++;
    }

    if (*str == '+') str++;

    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
            ret = ret * 10 + *str - '0';
	else
            assert(0);
        str++;
    }

    return is_negative? -ret: ret;
}


void test()
{
    int ret = atoi("2325");
    printf("%d\n", ret);

    ret = atoi("-124432");
    printf("%d\n", ret);

    ret = atoi("+45242");
    printf("%d\n", ret);


    ret = atoi("43dg54");
    printf("%d\n", ret);

}

int main()
{
    test();
}
