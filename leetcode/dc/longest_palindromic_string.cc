/*
http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html

 simpler approach, O(N2) time and O(1) space:
 In fact, we could solve it in O(N2) time without any extra space.

 We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2N-1 such centers.

 You might be asking why there are 2N-1 but not N centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as “abba”) and its center are between the two ‘b’s.

 Since expanding a palindrome around its center could take O(N) time, the overall complexity is O(N2).

Does an O(N) solution exist? You bet! However, it is not trivial and requires some very clever observation.*/

#include <string>
using namespace std;

//return the longest string around the center
string expend_around_center(string s, int c1, int c2)
{
    int l = c1, r = c2;
    int n = s.length();
    while (l >= 0 && r <= n - 1 && s[l] == s[r])
    {
        l--;
	r++;
    }
    return s.substr(l + 1, r - l - 1);
}

string longest_palindrome(string s)
{
    int n = s.length();
    if (n == 0) return "";
    string longest = s.substr(0 ,1);
    for (int i = 0; i < n - 1; i++)
    {
        //center is a char
        string p1 = expend_around_center(s, i, i);
	if (p1.length() > longest.length())
		longest = p1;

        //center is between two chars
	string p2 = expend_around_center(s, i, i + 1);
	if (p2.length() > longest.length())
		longest = p2;
    }
    return longest;
}
