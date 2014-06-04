/*
 *Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is val *id.
 *
 *The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>

int valid_parent(char* str)
{
    if (str == NULL) return 1;

    std::stack<char> mystack;
    while (*str != '\0')
    {
        if (*str == '(' || *str == '[' || *str == '{')
            mystack.push(*str);
        else if (*str == ')') 
        {
            if (mystack.top() == '(')
                mystack.pop();
            else
                return 0;
        }
        else if (*str == ']')
	{
	    if (mystack.top() == '[')
                mystack.pop();
	    else
                return 0;
        }
        else if (*str == '}')
        {
            if (mystack.top() == '{')
                mystack.pop();
            else
                return 0;
	}
        else
            return 0;
        str++;
    }
    if (!mystack.empty()) return 0;
    return 1;
}

void test()
{
    char* str1 = "({[]})";
    char* str2 = "({[[[]})";

    printf("%d\n", valid_parent(str1));
    printf("%d\n", valid_parent(str2));
}

int main()
{
    test();
}
