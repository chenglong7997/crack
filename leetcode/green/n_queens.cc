/*Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *         ["..Q.",  // Solution 2
 *          "Q...",
 *          "...Q",
 *          ".Q.."]
 * ]
 *
 * */

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

vector<vector<string> >  ret;
int counter = 0;

int is_valid(vector<int> &ans, int r)
{
    for (int i = 0; i < r; i++)
    {
        if (ans[i] == ans[r] || abs(ans[i] - ans[r]) == (r - i))
		return 0;
    }
    return 1;
}

void print_grid(vector<int> &ans, int n)
{
    vector<string> slu;
    string tmp(n, '.');

    for (int i = 0; i < n; i++)
    {
/*        for (int j = 0; j < n; j++)
            if (j == ans[i])
	    {    
                tmp.push_back('Q');
	        //cout<<"Q";
	    }
	    else 
	    {
                tmp.push_back('.');
	        //cout<<".";
	    }
*/
        tmp[ans[i]] = 'Q';    
	    //cout<<endl;
 	slu.push_back(tmp);
	tmp = "";
    }
    //cout<<endl;
    ret.push_back(slu);
}

void place_queen(vector<int> &ans, int cur, int n)
{
    //queen 1 problem
    /*if (cur == n) print_grid(ans, n);*/
    
    //queen 2 problem
    if (cur == n) {counter++; return;} 
    else
    {
        for (int i = 0; i < n; i++)
        {
            ans[cur] = i;
            if (is_valid(ans, cur))
                place_queen(ans, cur + 1, n);
        }
    }
}

vector<vector<string> > solve_nqueens(int n)
{
    //ans represent the index for every row
    vector<int> ans(n, -1);
    place_queen(ans, 0, n);
    return ret;
}

int main()
{
    //solve_nqueens(4);
    cout<<endl;
    solve_nqueens(5);
    cout<<"5 counter:"<<counter<<endl;
    //cout<<"5 kinds: "<<ret.size()<<endl;
    //ret.clear();
    counter = 0;

    cout<<endl;
    solve_nqueens(12);
    //cout<<"12 kinds: "<<ret.size()<<endl;
    cout<<"12 counter:"<<counter<<endl;
}
