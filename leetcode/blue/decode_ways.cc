#include <string>
#include <iostream>
using namespace std;

int check(char value)
{
    if ((value - '0') > 0 && (value - '0') <= 9) return 1;
    else return 0;
}

int check_two(char first, char second)
{
    if ((first - '0') > 0 && (first - '0') <= 2
		    && (second - '0') > 0 && (second - '0') <= 6)
        return 1;
    else
        return 0;
}

int num_decodings(string s)
{
    if (s.empty() || s[0] == '0') return 0;
    if (s.length() == 1)
    {
	    if (check(s[0])) return 1;
            else return 0;
    }
    int num1 = 0;

    string tmp(s, 1, s.length() - 1);
    if (check(s[0])) num1 = num_decodings(tmp);
    if (s.length() >= 2 && check_two(s[0], s[1])) 
    {
	    string tmp2(s, 2, s.length() - 2);
            int num2 = 0;
	    num2 = num_decodings(tmp2);
	    if (num2 == 0) num1++;
	    else
	        num1 += num2;;
    }
    return num1;
}


void test()
{
    string s = "12";
    cout<<num_decodings(s)<<endl;
    
    s = "2";
    cout<<num_decodings(s)<<endl;
    
    s = "123";
    cout<<num_decodings(s)<<endl;
    
}

int main()
{
    test();
}
