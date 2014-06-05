/*Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int remove_ele(int *array, int len, int target)
{
    int j = 0;
    for (int i = 0; i < len; i++)
    {
	if (array[i] != target)
            continue;
        for (j = i; j < len; j++)
	{
	    if (array[j] == target) continue;
	    array[i] = array[j];
	    array[j] = target;
	    break;
	}
	//all the remain equals target
	if (j == len)
	{
	    return i;
	}
    }
    return len;
}

void test()
{
    int array[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int new_len = remove_ele(array, 8, 2);
    printf("new_len %d\n", new_len);
    for (int i  = 0; i < new_len; i++)
        printf(" %d ", array[i]);
    printf("\n");
}

int main()
{
    test();
}
