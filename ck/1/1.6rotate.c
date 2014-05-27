/*
 *Given an image represendted by N * N matrix, where each pixel in the image is 4 bytes,
 *write a method to rotate the image by 90 degrees
 *follow up: can you do this in place?
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void rotate_test();
void rotate(int array[][4], int n);

int main()
{
    rotate_test();
}

void rotate_test()
{
    int array[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
	{9, 10, 11, 12},
	{13, 14, 15, 16}
    };
    rotate(array, 4);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf(" %d ", array[i][j]);
	printf("\n");
    }
}

void rotate(int array[][4], int n)
{
    if (n != 4) assert(0);
    int level = n / 2;
    int m = n;
    int tmp = 0;

    for (int i = 0; i < level; i++)
    {   // j range
        for (int j = i; j < m - i - 1; j++)
	{
             tmp = array[i][j];
             array[i][j] = array[j][m - i - 1];
	     array[j][m - i - 1] = array[m - i - 1][m - j - 1];
	     array[m - i - 1][m - j -1] = array[m - j - 1][i];
             array[m - j - 1][i] = tmp;
	}
    }
}


