/*
 *Given a string s, partition s such that every substring of the partition is a palindrome.
 *return the min cuts needed for a palindrome partitioning of s
 *
 * Ex: given s = "aab",
 * return 1 since the palindrome partitioning["aa", "b"] could be produced using 1 cut
 *
 *
 * D[i, n] = the min cut of [i, n]
 * a b a b b b a b b a b a
 *         i              n
 * a b a b b b a b b a b a
 *         i       j j+1  n
 *
 *
 * D[i, n] = min(D[i,j] + D[j + 1, n]) 1 <= j < n
 *
 * same as D[i] = min(1 + D[j + 1]) i <= j < n
 *
 * And use DP to check palindrome:
 * p[i][j] == true if [i,j] is a palindrome
 *
 * Then p[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]
 * */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int min_cut(string s)
{
    int len = s.size();
    // the worst case for D
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
