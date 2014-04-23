#include <stdio.h>
#include <stdlib.h>

void clear_matrix_zeros(int array[][5], int n);
void clear_matrix_zeros_test();

int main()
{
    clear_matrix_zeros_test();
}

void clear_matrix_zeros_test()
{
    int array[3][5] = {
	    {1, 2, 3, 4, 5},
	    {1, 2, 0, 4, 5},
	    {0, 2, 3, 4, 5}
    };
    clear_matrix_zeros(array, 3);
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            printf(" %d ", array[i][j]);
	printf("\n");
    }
}


void clear_matrix_zeros(int array[][5], int n)
{
    int *array_rows = (int*)calloc(n, sizeof(int));
    int array_cols[5] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (array[i][j] == 0)
            {
               array_rows[i] = 1;
               array_cols[j] = 1;
	    }
	}
    }

    //set zeros
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (array_rows[i] == 1 || array_cols[j] == 1)
                array[i][j] = 0;
	}
    }
}
