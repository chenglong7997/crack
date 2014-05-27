/*
 *implement a method to perform basic string compression using the counts of repeated characters
 *Ex: aabcccccaaa
 *    a2b1c5a3
 *If the "compressed" string would not become smaller than the original string, you method should
 *return the original string
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void compress_test();
void compress(char* src, char* dst);

int main()
{
    compress_test();
}

void compress_test()
{
    char* src = "aabcccccaaa";
    char dst[100] = {0};
    compress(src, dst);
    printf("%s\n", dst); 
}

void compress(char* src, char* dst)
{
    if (src == NULL)
        assert(0);
    char* slow = src;
    char* fast = src;
    int index = 0;
    int count = 1;
    char buffer[30] = {0};

    while (*slow != '\0')
    {
        if (*(++fast) == *slow)
            count++;
	else
	{
	    dst[index++] = *slow;
	    //itoa(count, buffer, 10);
            snprintf(buffer, sizeof(buffer), "%d", count);
	    strncpy(dst + index, buffer, strlen(buffer));
	    index += strlen(buffer);
            slow = fast;
	    count = 1;
	}
    }
    dst[index++] = '\0';

    if (index > strlen(src)) 
        strncpy(dst, src, strlen(src) + 1);
}
