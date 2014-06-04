/*
 *Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 * KMP
 * rolling hash
 * */

#include <stdio.h>
#include <stdlib.h>

char* str_str(char* str, char* target)
{
    if (str == NULL || target == NULL) return NULL;

    char* pslow = str;
    char* pfast = str;
    char* pt = target;

    while (*pslow != '\0')
    {
        if (*pslow == *pt)
	{
            pfast = pslow;
	    //there is a possible match
	    while (*pt != '\0' && *pfast != '\0')
	    {
	        if (*pt == *pfast)
		{
		    pt++;
		    pfast++;
		} else
			break;

	    }
	    if (*pt == '\0') return pslow;
	    if (*pfast == '\0') return NULL;
	
	    pt = target;
	}
	pslow++;
    }

    return NULL;
}

void test()
{
    char* str = "abcdefghi";
    char* target = "def";
    char* other = "sdf";

    char* tmp = str_str(str, target);
    
    char* tmp1 = str_str(str, other);

    if (tmp == NULL) printf("NULL");
    else printf("%s\n", tmp);
    
    if (tmp1 == NULL) printf("NULL");
    else printf("%s\n", tmp1);
}

int main()
{
    test();
}
