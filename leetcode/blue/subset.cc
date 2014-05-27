#include <iostream>
#include <vector>
using namespace std;

void do_subsets(int level, vector<int> &s, vector<vector<int> > &ret, vector<int> &solution);

vector<vector<int> > subsets(vector<int> &s)
{
    vector<vector<int> > ret;
    vector<int> solution;
    //the empty set
    ret.push_back(solution);
    if (s.size() == 0) return ret;
    sort(s.begin(), s.end());

    do_subsets(0, s, ret, solution);
    return ret;
}

void do_subsets(int level, vector<int> &s, vector<vector<int> > &ret, vector<int> &solution)
{
    for (int i = level; i < s.size(); i++)
    {
        solution.push_back(s[i]);
	ret.push_back(solution);
	
	if (level < (s.size() - 1))
            do_subsets(i + 1, s, ret, solution);
	solution.pop_back();
    }
}

void test()
{
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    vector<vector<int> > ret = subsets(s);
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
