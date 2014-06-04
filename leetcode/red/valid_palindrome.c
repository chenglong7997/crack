/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int valid_palindrome(char* str)
{
    if (str == NULL || *str == '\0') return 1;

    char* pstart = str;
    char* pend = str + strlen(str) - 1;
/*
    while (*pend != '\0')
	    pend++;
    pend--;
*/
    while (pstart < pend)
    {
        while (!isalnum(*pstart)) pstart++;
	while  (!isalnum(*pend)) pend--;
	if (tolower(*pstart) != tolower(*pend)) return 0;
        pstart++;
	pend--;
    }
    return 1;
}

void test()
{
    char* str1 = "A2 man, a plan, a canal: Panam2a";
    char* str2 = "race a car";

    printf("%d\n", valid_palindrome(str1));
    printf("%d\n", valid_palindrome(str2));
}

int main()
{
    test();
}
