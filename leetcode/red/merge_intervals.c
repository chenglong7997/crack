/*
 *Given a collection of intervals, merge all overlapping intervals.
 *
 *For example,
 *Given [1,3],[2,6],[8,10],[15,18],
 *return [1,6],[8,10],[15,18].
 * */


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
 
// An interval has start time and end time
struct Interval
{
    int start;
    int end;
};

// Compares two intervals according to their staring time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2)
{  return (i1.start < i2.start)? true: false; }

void merge_intervals(vector<Interval>& intervals)
{
    if (intervals.size() <= 0) return;
    stack<Interval> s;
    sort(intervals.begin(), intervals.end(), compareInterval);

    s.push(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        Interval top = s.top();

	if(top.end < intervals[i].start)
		s.push(intervals[i]);
	//there is overlap, update top if we really need.(top.end < intervals[i].end)
        else if (top.end < intervals[i].end)
	{
	    top.end = intervals[i].end;
	    s.pop();
	    s.push(top);
	}
    }

    cout<< "\n The merged intervals are:";
    while (!s.empty())
    {
        Interval t = s.top();
	cout << "[" << t.start << "," << t.end << "]" << " ";
	s.pop();
    }
    return;
}


void TestCase1()
{
    // Create a set of intervals
    Interval intvls[] = { {6,8}, {1,9}, {2,4}, {4,7} };
    vector<Interval> intervals(intvls, intvls+4);
    
    // Merge overlapping inervals and print result
    mergeIntervals(intervals);
}

void TestCase2()
{
    // Create a set of intervals
    Interval intvls[] = { {6,8},{1,3},{2,4},{4,7} };
    vector<Interval> intervals(intvls, intvls+4);
    
    // Merge overlapping inervals and print result
    mergeIntervals(intervals);
}

void TestCase3()
{
    // Create a set of intervals
    Interval intvls[] = { {1,3},{7,9},{4,6},{10,13} };
    vector<Interval> intervals(intvls, intvls+4);
    
    // Merge overlapping inervals and print result
    mergeIntervals(intervals);
}

// Driver program to test above functions
int main()
{
    TestCase1();
    TestCase2();
    TestCase3();
    return 0;
}
