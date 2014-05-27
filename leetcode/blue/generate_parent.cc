#include <iostream>
#include <vector>
#include <string>
using namespace std;

void gp(string str, int l, int r, int n, vector<string> &vs);

vector<string> generate_parenthesis(int n)
{
    vector<string> vs;
    if (n == 0) return vs;
    gp("",0,0,n,vs);
    return vs;
}

void gp(string str, int l, int r, int n, vector<string> &vs)
{
    if (l > n) return;
    if (l == n && r == n) vs.push_back(str);
    else
    {
        gp(str + '(', l + 1, r, n, vs);
	if (l > r) gp(str + ')', l, r + 1, n, vs);
    }
}

int main()
{
    vector<string> vs;
    vs = generate_parenthesis(3);
    for (int i = 0; i < vs.size(); i++)
	    cout<<" "<<vs[i]<<" "<<endl;
}

