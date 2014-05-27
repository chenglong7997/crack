#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longest(vector<int> &num)
{
    map<int, int> hashmap;
    int max = 0;
    int len = 0;
    for (int i = 0; i < num.size(); i++)
	    hashmap[num[i]] = 1;

    for (int i = 0; i < num.size(); i++)
    {
        len = 1;
	int left = num[i] - 1;
	int right = num[i] + 1;
	//exist the key
	while(hashmap.count(left))
	{
            hashmap.erase(left);
	    len++;
	    left--;
	}
	while(hashmap.count(right))
	{
	    hashmap.erase(right);
	    len++;
	    right++;
	}
	if (len > max) max = len; 
        hashmap.erase(num[i]);
    }

    return max;
}

void test()
{
    int array[] = {100, 4, 200, 1, 3, 2};
    vector<int> num(array, array + sizeof(array)/sizeof(int));
    cout<<longest(num)<<endl;
}

int main()
{
    test();
}
