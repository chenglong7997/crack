#include <iostream>
#include <vector>
using namespace std;

int unique_paths_2(vector<vector<int> > &obstacle_grid)
{
    if (obstacle_grid.size() == 0) return 0;

    int m = obstacle_grid.size();
    int n = obstacle_grid[0].size();

    vector<int> ans(n, 0);
    ans[0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
	{
	    if (obstacle_grid[i][j] == 1)
                ans[j] = 0;
	    else
                ans[j] += ans[j - 1];
	}
    }
    return ans[n - 1];
}

void test()
{
    vector<vector<int> > obstacle_grid;
    vector<int> line(3, 0);
    obstacle_grid.push_back(line);
    line[1] = 1;
    obstacle_grid.push_back(line);
    line[1] = 0;
    obstacle_grid.push_back(line);

    cout<<"paths: "<<unique_paths_2(obstacle_grid)<<endl;
}

int main()
{
    test();
}
