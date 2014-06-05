/*
 *Given a roman numeral, convert it to an integer.
 *
 *Input is guaranteed to be within the range from 1 to 3999.
 *
 * scan from front to back.
 * if current if bigger than previous, then tmp  = current - previous
 * else ret += tmp.
 * */

#include <iostream>
#include <string>
using namespace std;

int c2n(char c)
{
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int roman_to_int(string str)
{
    int tmp = 0;
    int ret = 0;
    for (int i = 0; i < str.length(); i++)
    {
	if (tmp >= c2n(str[i]))
	{
            tmp = c2n(str[i]);
            ret += tmp;
        } else {
            //2tmp since the first if add once
	    ret = ret + c2n(str[i]) - 2*tmp;
	    tmp = c2n(str[i]);
	}
    }
    return ret;
}

void test()
{
    printf("MCMLXXX %d\n", roman_to_int("MCMLXXX"));
    printf("XLV %d\n", roman_to_int("XLV"));
}

int main()
{
    test();
}
