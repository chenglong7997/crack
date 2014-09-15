/*Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.*/


#include <stdio.h>
#include <assert.h>

int atoi(char* str)
{
    if (str == NULL) assert(0);
    int is_negative = 0;
    int ret = 0;

    //ingore the spaces before string
    while (*str == ' ' && *str != '\0') str++;
    if (*str == '-')
    {
        is_negative = 1;
        str++;
    } else if (*str == '+') str++;

    while (*str != '\0')
    {
        //ingore the spaces in string
        if (*str == ' ') break;
        if (*str < '0' || *str > '9') break;
	//hanle overflow
	if (INT_MAX/10 < num || INT_MAX/10 == num && INT_MAX % 10 < (*str - '0'))
		return is_negative? INT_MIN : INT_MAX;

        ret = ret * 10 + *str - '0';
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
