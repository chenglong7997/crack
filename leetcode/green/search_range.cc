/*Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 * */

#include <iostream>
#include <vector>
using namespace std;

vector<int> search_range(int a[], int n, int target)
{
    vector<int> ans(2, -1);
    if (n <= 0) return ans;

    int start = 0;
    int end = n - 1;
    int mid = 0;

    //for lower index
    while (start < end)
    {
        mid = (start + end) / 2;
        if (a[mid] < target)
	{
	    start = mid + 1;
	}else
            end = mid;
    }

    int lower = a[start] == target? start : -1;
    ans[0] = lower;
    if (lower == -1)
	return ans;

    //for upper index 
    start = lower;
    end = n - 1;
    while (start < end)
    {
        mid = (start + end)/2;
        if (a[mid] > target)
	{
	    end = mid;
	}else
            start = mid + 1;
    }
    int upper = end - 1;
    ans[1] = upper;
    return ans;
}

void test()
{
    int a [] = {1,2,3,4,7,7,7,7,8,8,8,8,9,9};
    vector<int> ret = search_range(a, 14, 8);
    cout<<ret[0]<<endl;
    cout<<ret[1]<<endl;
}

int main()
{
    test();
}
