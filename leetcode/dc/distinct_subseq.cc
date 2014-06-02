#include <string>
using namespace std;

//recursive solution, can be solved using DP.
//will write it if have time
int cond(string s, string t)
{
    if (s.size() == 0) return 0;
    //?
    if (t.size() == 0) return 1;

    if (s.size() == 1 && t.size() == 1)
    {
        if (s[0] == t[0]) return 1;
	else return 0;
    }

    if (s[0] == t[0])
	    return cond(s.substr(1), t.substr(1)) + cond(s.substr(1), t);
    else
	    return cond(s.substr(1), t);
}

int num_dis(string s, string t)
{
    if (s.empty() || t.empty()) return 0;
    return cond(s, t);
}


int main()
{

}
