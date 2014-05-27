#include <iostream>
#include <string>
#include <vector>
using namespace std;

void restore(string s, int start, int partition_num, string result_ip, vector<string> &ans)
{
    if (s.length() - start > (4 - partition_num) * 3 ||
        s.length() - start < (4 - partition_num)) return;    

    int num = 0;
    if (partition_num == 4 && start == s.length())
    {
        //remove the last '.'
	result_ip.resize(result_ip.length() - 1);
        ans.push_back(result_ip);
        return;
    }

    for (int i = start; i < start + 3; i++)
    {
        num = num * 10 + (s[i] - '0');
	if (num <= 255)
	{
            result_ip += s[i];
	    restore(s, i + 1, partition_num + 1, result_ip + '.', ans);
	}
	if (num == 0)
		break;
    }
}

vector<string> restore_ip(string s)
{
    vector<string> ans;
    string result_ip;
    restore(s, 0, 0, result_ip, ans);
    return ans;
}

void test()
{
    //string s = "25525511135";
    //string s = "2025511135";
    //string s = "1101010";
    string s = "0000";
    vector<string> ret = restore_ip(s);
    for (int i = 0; i < ret.size(); i++)
	    cout<<ret[i]<<endl;
}

int main()
{
    test();
}
