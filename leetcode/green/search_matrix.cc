#include <iostream>
#include <vector>

using namespace std;

int search_matrix(vector<vector<int> > &matrix, int target)
{
    if (matrix.empty()) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int start = 0;
    int end = m * n - 1;
    int mid = 0;
    int x = 0;
    int y = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;
        x = mid / n;
	y = mid % n;
	if (matrix[x][y] == target) return 1;
	else if (matrix[x][y] < target) start = mid + 1;
	else end = mid - 1;
    }
    return 0;
}

void test()
{
    vector<vector<int> > grid;
    vector<int> row;
    row.push_back(1);
    row.push_back(3);
    row.push_back(5);
    row.push_back(7);
    grid.push_back(row);

    vector<int> row2;
    row2.push_back(10);
    row2.push_back(11);
    row2.push_back(16);
    row2.push_back(20);
    grid.push_back(row2);
    
    vector<int> row3;
    row3.push_back(23);
    row3.push_back(30);
    row3.push_back(34);
    row3.push_back(50);
    grid.push_back(row3);

    cout<<search_matrix(grid, 34)<<endl;
    cout<<search_matrix(grid, 50)<<endl;
    cout<<search_matrix(grid, 1)<<endl;
    cout<<search_matrix(grid, 0)<<endl;
}

int main()
{
    test();
}

