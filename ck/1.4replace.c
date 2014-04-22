#include <stdio.h>
#include <stdlib.h>

void replace_test();
void replace(char* str);

int main()
{
    replace_test();    
}

void replace_test()
{
    char array[256] = {'M', 'r', ' ', 'J', 'o', 'h', 'n', ' ', '\0'}; 
    replace(array);
    
    for (int i = 0; i < 256; i++)
        if (array[i] != '\0')
            printf("%c", array[i]);
        else
	    break;

    printf("\n");
}

void replace(char* str)
{
    int spaces = 0;
    char* pscan = str;

    while (*pscan != '\0')
    {
        if (*pscan == ' ')
	    spaces++;
        pscan++;
    }
    
    char* plater = 2 * spaces + pscan; //a little trick
    char* pfirst = pscan;

    while (pfirst != str)
    {
        if (*pfirst != ' ')
	{
            *plater = *pfirst;
	    plater--;
	    pfirst--;
	} else {
	    *plater-- = '0';
	    *plater-- = '2';
	    *plater-- = '%';
	    pfirst--;
	}
    }
}
