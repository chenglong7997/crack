/*Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 * */

#include <iostream>
#include <string>
using namespace std;

string multiply(string num1, string num2)
{
    if (num1.empty()) return num2;
    if (num2.empty()) return num1;
    string ret(num1.size() + num2.size(), '0');
    int num2_digit = 0;
    int num1_digit = 0;
    int carry  = 0;
    int total_len = ret.size();
    int pre_ret = 0;

    //multiply from back to front
    for (int i = num2.size() - 1; i >= 0; i--)
    {
        num2_digit = num2[i] - '0';
        for (int j = num1.size() - 1; j >= 0; j--)
        {
	    num1_digit = num1[j] - '0';
	    pre_ret = ret[i + j + 1] - '0';
	    ret[i + j + 1] = ( (pre_ret + num1_digit * num2_digit + carry) % 10) + '0';
	    carry = (pre_ret + num1_digit * num2_digit + carry) / 10;
	}
	if (carry) ret[i] += carry;
	carry = 0;
    }

    //remove the leading zeros
    int start = 0;
    for (int i = 0; i < ret.size(); i++)
        if (ret[i] == '0') ++start;

    return ret.substr(start, ret.size() - start);
}

void test()
{
    string num1 = "3542";
    string num2 = "123";
    cout<<multiply(num1, num2)<<endl;
}

int main()
{
    test();
}
