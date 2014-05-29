/*
 *searches for a value in an n * m table. This table is sorted along the rows
 *and columes--that is
 *
 *table[i][j] <= table[i][j + 1]
 *table[i][j] <= table[i + 1][j]
 * */

#include <stdio.h>
#include <stdlib.h>

//return 1, if exists. Otherwise, return 0
int search_matrix(int a[][m], int n, int target)
{
    if (target < a[0][0] || target > a[n- 1][m - 1])
        return 0;

    int i = 0;
    int j = m - 1;
    while (i <= n - 1 && j >= 0)
    {
        if (target > a[i][j]) i++;
	if (target < a[i][j]) j--;
        if (target == a[i][j]) return 1;
    }

    return 0;
}

int main()
{

}
