#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int min_cut(string s)
{
    int len = s.size();
    vector<int> D(len, 0);
    int P[len][len];
    for (int i = 0; i < len; i++)
        D[i] = len - i - 1;

    memset(P, 0, len * len);

    for (int i = len - 2; i >= 0; i--)
    {
        for (int j = i; j < len; j++)
        {
	    if (s[i] == s[j] && (P[i + 1][j - 1] || j - i < 2))
	    {
                P[i][j] = 1;
	        D[i] = min(D[i], D[j + 1] + 1);
	    }
	}
    }
    return D[0];
}

void test()
{
    string s = "aab";
    cout<<"min cut = "<<min_cut(s)<<endl;
}

int main()
{
    test();
}
