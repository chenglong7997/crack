#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string> > ans;
vector<string> par;

int is_palindrome(string &s, int start, int end)
{
    if (start == end) return 1;
    while (start < end)
    {
        if (s[start] != s[end]) return 0;
	start++;
	end--;
    }
    return 1;
}

void dfs(string &s, int start)
{
    if (start == s.length())
    {
        ans.push_back(par);
        return;
    }

    for (int i = start; i < s.length(); i++)
    {
        if (is_palindrome(s, start, i))
	{
            //substr function...
	    par.push_back(s.substr(start, i - start + 1));
	    dfs(s, i + 1);
	    par.pop_back();
	}
    }
}

vector<vector<string> > partition(string s)
{
    //clear function
    par.clear();
    ans.clear();
    dfs(s, 0);

    return ans;    
}

void test()
{
    string s = "aab";
    partition(s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"[";
        for (int j = 0; j < ans[i].size(); j++)
	{
	    cout<<ans[i][j]<<" ";
	}
	cout<<"]"<<endl;
    }
}

int main()
{
    test();
}
