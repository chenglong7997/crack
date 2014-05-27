#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*notes: TODO add set to unique the answers*/
void three_sum(int *array, int len)
{
    if (array == NULL) return;
    int sum_2 = 0;
    int remain = 0;

    for (int i = 0; i < len; i ++)
    {
        sum_2 = -array[i];
        for (int j = i + 1; j < len; j++)
	{
	    remain = sum_2 - array[j];
            for (int k = j + 1; k < len; k++)
	    {
	        if (array[k] == remain)
	            printf("%d, %d, %d\n", array[i], array[j], array[k]);
	    }
	}
    }
}

void test()
{
    int array[6] = {-1, 0, 1, 2, -1, -4};
    three_sum(array, 6);
}

int main()
{
    test();
}
