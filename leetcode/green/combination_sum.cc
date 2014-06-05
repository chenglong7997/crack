/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 *
 * DFS
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int> &candidates, int target, vector<vector<int> > &ret, vector<int> &cur, int index);

vector<vector<int> > combination_sum(vector<int> &candidates, int target)
{
    vector<vector<int> > ret;
    sort(candidates.begin(), candidates.end());
    if (target <= 0) return ret;

    vector<int> cur;
    helper(candidates, target, ret, cur, 0);
    return ret;
}

void helper(vector<int> &candidates, int target, vector<vector<int> > &ret, vector<int> &cur, int index)
{
    if (target == 0)
    {
        ret.push_back(cur);
        return;
    }else if (target < 0)
        return;

    if (index >= candidates.size()) return;

    for (int i = index; i < candidates.size(); i++)
    {
        cur.push_back(candidates[i]);
        helper(candidates, target - candidates[i], ret, cur, i);
        cur.pop_back();
    }

    return;
}

void test()
{
    vector<int> can;
    can.push_back(2);
    can.push_back(3);
    can.push_back(6);
    can.push_back(7);

    vector<vector<int> > ret =  combination_sum(can, 7);

    for (int i = 0; i < ret.size(); i++)
    {
        for(int j = 0; j < ret[i].size(); j++)
	{
	    cout<<ret[i][j];
	}
	cout<<endl;
    }
}

int main()
{
    test();
}
