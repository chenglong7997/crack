#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//O(n^2)
//sort the array
//for each element, find the 2sum after the current element
void three_sum_sort(vector<int>& array_v)
{
    sort(array_v.begin(), array_v.end());
    int j = 0;
    int k = 0;
    for (int i = 0; i < array_v.size(); i++)
    {
        //avoid duplicate
        if (i && array_v[i] == array_v[i - 1]) continue;

        j = i + 1;
	k = array_v.size() - 1;
        while (j < k)
	{
	    if ((array_v[j] + array_v[k]) < -array_v[i]) j++;
	    else if ((array_v[j] + array_v[k]) > -array_v[i]) k--;
	    else
	    {
		cout<<"i"<<i<<"j"<<j<<"k"<<k<<endl;
                cout<<"("<< array_v[i] <<","<< array_v[j]<<","<<array_v[k] << ")" << endl;
	        j++;
		k--;
		//avoid duplicate
                while (j < k && array_v[j] == array_v[j - 1]) j++;
                while (j < k && array_v[k] == array_v[k - 1]) k--;
	    }
	}
    }
}



void test()
{
    int array[] = {-1, -1, 0, 0, 1, 1, 2, -1, -4};
    vector<int> array_v(array, array+8);
    three_sum_sort(array_v);

    int array_a[] = {-2, 0, 0, 1, 2};
    vector<int> array_va(array_a, array_a+5);
    three_sum_sort(array_va);
}

int main()
{
    test();
}
