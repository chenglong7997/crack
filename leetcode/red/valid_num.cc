#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define false 0
#define true 1

int valid(char* s, int has_dot);

    int isNumber(const char *s) {
        if (s == NULL) return false;

        char tmp[strlen(s) + 1];
        memset(tmp, 0, strlen(s) + 1);
        strncpy(tmp, s, strlen(s) + 1);
        //avoid "3e" which is the false
        if (strlen(s) > 0 && (s[strlen(s) - 1] == 'e' || s[0] == 'e'))
            return false;

        char* first = strtok(tmp, "e");
        char* last = strtok(NULL, "e");

        int ret = valid(first, false);
        if (last != NULL)
            ret = ret && valid(last, true);
        return ret;
    }

int valid(char* s, int has_dot)
{
    //avoid "1+". "+", "+."
    if (strlen(s) > 0 && (s[0] == '+' || s[0] == '-')) s++;

    //avoid a single "=", "."
    if (strlen(s) == 0 || (*s == '.' && strlen(s) == 1)) return false;

    while (*s != '\0')
    {
        if (*s == '.')
        {
            if (has_dot) return false;
            has_dot = true;
        }
        else if (!(*s >= '0' && *s <= '9')) return false;
        s++;
    }
    return true;
}

int main()
{
    char *str = "234.2e23";
    printf("ret %d\n", isNumber(str));

    str = "+234.2e23";
    printf("ret %d\n", isNumber(str));

    str = "2.34.2e23";
    printf("ret %d\n", isNumber(str));

    str = "1";
    printf("ret %d\n", isNumber(str));
}

