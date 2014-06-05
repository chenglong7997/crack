/*Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 *
 * */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> anagrams(vector<string> &strs)
{
    map<string, vector<string> > mp;
    vector<string> ans;
    string tmp;

    for (int i = 0; i < strs.size(); i++)
    {
        tmp = strs[i];
	sort(tmp.begin(), tmp.end());
	mp[tmp].push_back(strs[i]);
    }

    for (map<string, vector<string> >::iterator p = mp.begin(); p != mp.end(); p++)
    {
        if ((p->second).size() > 1)
	{
	    for (int i = 0; i < (p->second).size(); i++)
		    ans.push_back((p->second)[i]);
	}
    }
    return ans;
}
