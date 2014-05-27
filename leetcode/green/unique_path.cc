#include <iostream>
#include <vector>
using namespace std;


//
//combination problems C(8, 2) C(m + n - 2, m - 1) 
/*
int unique_paths(int m, int n)
{
    vector<int> ans(n, 1);


    //both i and j start from 1
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
            ans[j] = ans[j - 1] + ans[j];
    }

    return ans[n - 1];
}
*/

int unique_paths(int m, int n)
{
    vector<int> ans(n, 0);
    ans[0] = 1;

    for(int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
            ans[j] += ans[j - 1];
    }

    return ans[n - 1];
}

void test()
{
    cout<<"paths: "<<unique_paths(7, 3)<<endl;
}

int main()
{
    test();
}
