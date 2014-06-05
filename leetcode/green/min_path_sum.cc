/*
 *given a m * n grid filled with non-negative numbers, find a path from top left to bottom right
 *which minimizes the sum of all numbers along its path.
 *
 *You can only move either down or right at any point in time
 *
 *DP problem, using a rolling row to store previous results
 * */

#include <iostream>
#include <vector>
#include <assert.h>
#include <limits.h>
#include <algorithm>
using namespace std;

//rolling array to store the cost
int min_path_sum(vector<vector<int> > &grid)
{
    if (grid.size() == 0) assert(0);
    int m = grid.size();
    int n = grid[0].size();

    vector<int> ans(n, INT_MAX);
    ans[0] = 0;

    for (int i = 0; i < m; i++)
    {
        ans[0] += grid[i][0];
        for (int j = 1; j < n; j++)
	{
	    ans[j] = min(ans[j - 1], ans[j]) + grid[i][j];
	}
    }

    for (int i = 0; i < n; i++)
	    cout<<ans[i]<<endl;
    cout<<endl;
    return ans[n - 1];
}


void test()
{
    vector<vector<int> > grid;
    vector<int> row;
    row.push_back(9);
    row.push_back(10);
    row.push_back(15);
    grid.push_back(row);

    vector<int> row2;
    row2.push_back(13);
    row2.push_back(8);
    row2.push_back(14);
    grid.push_back(row2);
    
    vector<int> row3;
    row3.push_back(12);
    row3.push_back(11);
    row3.push_back(16);
    grid.push_back(row3);
    cout<<grid[0][0]<<endl;
    cout<<grid[0][1]<<endl;
    cout<<"cost: "<<min_path_sum(grid)<<endl;
}

int main()
{
    test();
}
