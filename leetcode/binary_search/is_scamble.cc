/*
 *if s2 is a scramble of s1
 *
 * */

#include <string>
#include <iostream>
using namespace std;

int is_scramble(string s1, string s2)
{
    if (s1.size() != s2.size()) return 0;
    int a[26] = {0};

    int ret = 0;
    int size = s1.size();

    for (int i = 0; i < s1.size(); i++)
    {
        a[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (a[s2[i] - 'a'] <= 0)
		return 0;
	else
            a[s2[i] - 'a']--;
    }
    
    if (s1.size() == 1) return 1;
    for (int i = 1; i < s1.size(); i++)
    {
        ret = is_scramble(s1.substr(0, i), s2.substr(0, i)) && is_scramble(s1.substr(i), s2.substr(i));

	ret = ret || (is_scramble(s1.substr(0, i), s2.substr(size - i)) && is_scramble(s1.substr(i), s2.substr(0, size - i)));
        if (ret)
		return 1;
    }
    return 0;
}

void test()
{
    string s1 = "great";
    string s2 = "rgeat";
    string s3 = "rgtae";
    cout<<is_scramble(s1, s2)<<endl;
    cout<<is_scramble(s1, s3)<<endl;
    cout<<is_scramble(s2, s3)<<endl;
}

int main()
{
    test();
}
