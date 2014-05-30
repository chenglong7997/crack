/*
 *find the intersection of two sorted arrays
 *
 * Hash can also offer O(n) time
 * If one array is very big, can do binary search using little array
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<int> find_intersection(vector<int> a, vector<int> b)
{
    vector<int> intersection;
    int a_len = a.size();
    int b_len = b.size();
    int i = 0;
    int j = 0;
    while (i <= a_len && j <= b_len)
    {
        if (a[i] > b[j])
	    j++;
	else if (a[i] < b[j])
            i++;
	else
	{
	    intersection.push_back(a[i]);
	    i++;
	    j++;
	}
    }

    return intersection;
}

void test()
{
    int array_a[] = {1, 3, 5, 7, 9, 10};
    int array_b[] = {2, 5, 8, 9, 11};
    vector<int> a(array_a, array_a + 6);
    vector<int> b(array_b, array_b + 5);

    vector<int> ret = find_intersection(a, b);

    for (int i = 0; i < ret.size(); i++)
	    cout<<ret[i]<<endl;
}

int main()
{
    test();
}
