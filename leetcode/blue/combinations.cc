#include <iostream>
#include <vector>
using namespace std;

void do_combine(int start, int end, int k, vector<int> &solution, vector<vector<int> > &ret);

vector<vector<int> > combine(int n, int k)
{
    vector<vector<int> > ret;
    vector<int> solution;
    do_combine(1, n + 1, k, solution, ret);
    return ret;
}

void do_combine(int start, int end, int k, vector<int> &solution, vector<vector<int> > &ret)
{
    if (k == 0)
    {
        ret.push_back(solution);
	    return;
    }
    /*if (k == 1)
    {
        for (int i = start; i < end; i++)
	{
            solution.push_back(i);
            ret.push_back(solution);
	    solution.pop_back();
	}
	return;
    }*/

    for(int i = start; i < end; i++)
    {
        solution.push_back(i);
        do_combine(i + 1, end, k - 1, solution, ret);
	solution.pop_back();
    }
}

void test()
{
    vector<vector<int> > ret = combine(5, 2);
//    ret = combine(5, 5);
    //ret = combine(5, 2);
    for (int i = 0; i < ret.size(); i++)
    {
        cout<<"[";
        for (int j = 0; j < ret[i].size(); j++)
            cout<<ret[i][j]<<" ";
        cout<<"]";
    }
    cout<<endl;
}

int main()
{
    test();
}
