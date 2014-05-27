#include <iostream>
#include <string>
using namespace std;

string add_binary(string a, string b)
{
    if (a.empty() || b.empty()) return a + b;
    string c;
    int carry = 0;
    int inta = 0;
    int intb = 0;
    int sum = 0;
    int i = 0;
    int j = 0;
    for (i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--)
    {
	    sum = 0;
	    if (j <= -1)
	    {
	        inta = a[i] - '0';
		sum = inta + carry;
	    }
	    else if (i <= -1)
	    {
	        intb = b[j] - '0';
		sum = intb + carry;
	    }
	    else
	    {
                inta = a[i] - '0';
	        intb = b[j] - '0';
	        sum = inta + intb + carry;
	    }
	    
	    if (sum == 3)
	    {
                c = '1' + c;
	        carry = 1;
	    }
	    else if (sum == 2)
	    {
                c = '0' + c;
	        carry = 1;
	    }
	    else if (sum == 1)
	    {
                c = '1' + c;
	        carry = 0;
	    }
	    else if (sum == 0) 
	    {
                c = '0' + c;
	        carry = 0;
	    }
    }

    if (carry == 1) c = '1' + c;    
    return c;
}

void test()
{
    string a = "11";
    string b = "1";
    string ret = add_binary(a, b);
    cout<<"ret: "<<ret<<endl;

    a = "111";
    b = "11";
    ret = add_binary(a, b);
    cout<<"ret: "<<ret<<endl;
}

int main()
{
    test();
}
