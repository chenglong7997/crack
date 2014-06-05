/*
 *Given an integer, convert it to a roman numeral.

 Input is guaranteed to be within the range from 1 to 3999
 * */

#include <iostream>
#include <string>
using namespace std;

/*
 *I 1, V 5,
 *X 10, L 50,
 *C 100, D 500
 *M 1000
 *
 *
 *1-3 I, II, III,
 *4 IV,
 *5 V
 *6~8 VI, VII, VIII
 *9 IX
 *10 X
 *
 * */

string int_to_roman(int num)
{
    char* roman = "IVXLCDM";
    int scale = 1000;
    string ret;
    int digit;

    for (int i = 6; i >= 0; i -= 2)
    {
        digit = num / scale;
	if (digit != 0)
	{
	    if (digit <= 3) ret.append(digit, roman[i]);
	    if (digit == 4)
	    {
	        ret += roman[i];
		ret += roman[i + 1];
	    }
	    else if (digit == 5) ret += roman[i + 1];
	    else if (digit >=6 && digit <=8)
	    {
	        ret += roman[i + 1];
		ret.append((digit - 5), roman[i]);
	    }
	    else if (digit == 9)
	    {
	        ret += roman[i];
		ret += roman[i + 2];
	    }
	}
	num = num % scale;
	scale /= 10;
    }
    return ret;
}


void test()
{
    cout <<"1980(MCMLXXX):"<<int_to_roman(1980)<<endl;
    cout <<"45(XLV):" << int_to_roman(45)<<endl;
    cout<<"3"<<int_to_roman(3)<<endl;
}

int main()
{
    test();
}
