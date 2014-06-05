/*Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 *
 * */

#include <stdlib.h>
#include <stdio.h>

int is_match(char *s, char *p)
{
    int start = 0;
    char *str, *ptr;

    for (str = s, ptr = p; *str != '\0'; str++, ptr++)
    {
        switch(*ptr)
	{
	    case '?':
                break;
            case '*':
                star = 1;
                s = str, p = ptr;
                while (*p == '*')
                    p++;
                //if there is nothing after '*', return 1
                if (*p == '\0')
                    return 1;
                str = s - 1;
                ptr = p - 1;
                break;
            default:
		    {
		        if (*str != *ptr)
			{
			    //if there is no "*" before, return 0
			    if (!str)
				    return 0;
			    s++;
			    str = s - 1;
			    ptr = p - 1;
			}
		    }
	}
    }
    while (*ptr == '*')
	    ptr++;

    return *ptr == '\0';
}
