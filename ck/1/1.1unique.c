#include <stdio.h>
#include <stdlib.h>

void unique_test();
int unique(char* str);
int unique_hash(char* str);
int unique_bitmap(char* str);

int main()
{
    unique_test();
}

void unique_test()
{
    char* string1 = "You are the hero!";
    char* string2 = "abc defg";
    printf("%d\n",unique(string1));
    printf("%d\n",unique(string2));
    
    printf("%d\n",unique_hash(string1));
    printf("%d\n",unique_hash(string2));
    
    printf("%d\n",unique_bitmap(string1));
    printf("%d\n",unique_bitmap(string2));
}

int unique_bitmap(char* str)
{
    if (str == NULL || *str == '\0') return 1;
    char bitmap[256 / sizeof(char)] = {0};
    while (*str != '\0')
    {
        if ((bitmap[*str / sizeof(char)] & (1 >> (*str % sizeof(char)))) == 0)
	    bitmap[*str / sizeof(char)] = 1;
	else
	    return 0;
	str++;
    }
    return 1;
}

int unique_hash(char* str)
{
    if (str == NULL || *str == '\0') return 1;
    char hash[256] = {0};
    while (*str != '\0')
    {
        if (hash[*str] == 0)
            hash[*str] = 1;
	else
	    return 0;
        str++;
    }
    return 1;
}

int unique(char* str)
{
    if (str == NULL || *str == '\0') return 1;

    char* pscan = str + 1;
    while (*str != '\0')
    {
        pscan = str + 1;
	while (*pscan != '\0')
	{
            if (*pscan == *str)
	        return 0;
            pscan++;
	}
	str++;
    }
    return 1;
}
