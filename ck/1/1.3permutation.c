#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_permutation(char* str1, char* str2);
void is_permutation_test();

int main()
{
    is_permutation_test();
}

void is_permutation_test()
{
    char* str1 = "abcdefg";
    char* str2 = "bcdefga";
    char* str3 = "cool";
    printf("%d\n", is_permutation(str1, str2));
    printf("%d\n", is_permutation(str1, str3));
}

/*1. sort*/
/*2. helper array*/
int is_permutation(char* str1, char* str2)
{
    if (str1 == NULL || str2 == NULL)
        assert(0);

    int len1 = 0;
    int len2 = 0;
    
    char array[256] = {0};
    char* pscan1 = str1;
    char* pscan2 = str2;
    while (*pscan1 != '\0')
    {
        array[*pscan1] += 1;
	pscan1++;
	len1++;
    }
    while (*pscan2 != '\0')
    {
        array[*pscan2] -= 1;
	if (array[*pscan2] < 0)
	    return 0;
	pscan2++;
	len2++;
    }
    if (len1 == len2)
        return 1;
    else
        return 0;
}
