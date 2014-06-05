/*Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string array[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

vector<string> letter_com(string digits)
{
    vector<string> ret;
    if (digits.empty()) return ret; 
    if (digits.size() == 1)
    {
        int index = digits[0] - '0';
        for (int i = 0; i < array[digits[0] - '0'].size(); i++)
	    ret.push_back( string(1, array[index][i]) );
	return ret;
    }

    vector<string> remain = letter_com(digits.substr(1));
    
    int index = digits[0] - '0';
    for (int i = 0; i < array[index].size(); i++)
    {
	if (remain.size() == 0)
		ret.push_back(string(1, array[index][i]));
        else
            for (int j = 0; j < remain.size(); j++)
                ret.push_back(array[index][i] + remain[j]);
    }

    if (array[index].size() == 0) //this is 0 / 1
        ret = remain;

    return ret;
}

void test()
{
    vector<string> ans= letter_com("203");
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}

int main()
{
    test();
}
