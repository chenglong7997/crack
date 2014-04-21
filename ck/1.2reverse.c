#include <stdio.h>
#include <stdlib.h>

void reverse_test();
void reverse(char* str);

int main()
{
    reverse_test();
}

void reverse_test()
{
    char str[] = "you are the man";
    reverse(str);
    char* pscan = str;
    while (*pscan != '\0')
    {
        printf("%c", *pscan);
        pscan++;
    }
    printf("\n");
}

void reverse(char* str)
{
    if (str == NULL || *str == '\0') return;

    char *pstart = str;
    char *pend = str;
    char tmp = ' ';

    while (*(pend + 1) != '\0')
        pend++;
    while (pstart <= pend)
    {
        tmp = *pstart;
	*pstart = *pend;
	*pend = tmp;
	pend--;
	pstart++;
    }
}
