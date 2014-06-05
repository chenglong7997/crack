/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * use hash table, and search as the current number is the center, extend to left and extend to right
 * */

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
