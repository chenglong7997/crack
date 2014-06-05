/*Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 * */

#include <iostream>
#include <vector>
using namespace std;


void do_permute(vector<int> &num, int level, vector<int> &solution, vector<int> &visited, vector<vector<int> > &ret)
{
    if (level == num.size())
    { 
        ret.push_back(solution);
     	return;
    }

    for (int i = 0; i < num.size(); i++)
    {
        if (visited[i]) { /*cout<<"continue"<<endl;*/ continue;}

	solution.push_back(num[i]);
	visited[i] = 1;
	do_permute(num, level + 1, solution, visited, ret);
        //pop back the last one
	solution.pop_back();
	visited[i] = 0;
    }
}

vector<vector<int> > permute(vector<int> &num)
{
    vector<vector<int> > ret;
    vector<int> solution;
    //important to init the visited array
    vector<int> visited(num.size(), 0);
    int level = 0;
    do_permute(num, level, solution, visited, ret);
    
    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
	{
	    cout<<" "<<ret[i][j]<<" ";
	}
	cout<<endl;
    }
    return ret;
}

void test()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
//    num.push_back(4);

    permute(num);
}

int main()
{
    test();
}
