#include <string>
using namespace std;

//recursive solution, will add DP if have time

int is_interleave(string s1, string s2, string s3)
{
    if (s1.lenght() + s2.length() != s3.length()) return 0;
    return rec(s1, 0, s2, 0, s3, 0);
}

int rec(string s1, int p1, string s2, int p2, string s3, p3)
{
    if (p3 == s3.length()) return 1;
    if (p1 == s1.length()) return s2.substr(p2) == s3.substr(p3);
    if (p2 == s2.length()) return s1.substr(p1) == s3.substr(p3);

    if (s1[p1] == s3[p3] && s1[p1] == s2[p2])
	    return rec(s1, p1 + 1, s2, p2, s3, p3+1) || rec(s1, p1, s2, p2+1, s3, p3+1);
    else if (s1[p1] == s3[p3])
	    return rec(s1, p1+1, s2, p2, s3, p3+1);
    else if (s2[p2] == s3[p3])
	    return rec(s1, p1, s2, p2 + 1, s3, p3+1);
    else
	    return 0;
}
