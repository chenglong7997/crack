/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

 You may assume that the intervals were initially sorted according to their start times.

 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */
#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
    int start;
    int end;
};

vector<Interval> insert(vector<Interval> &intervals, Interval new_interval)
{
    vector<Interval>::iterator it = intervals.begin();
    while (it != intervals.end())
    {
    	//insert before it
        if (new_interval.end < it->start)
	{
	    intervals.insert(it, new_interval);
	    return intervals;
	} //try to insert after it
	else if (new_intervals.start > it->end)
	{
	    it++;
	    continue;
	}
	else //update the new_interval with it, and try to insert it with it->next
	{
	    new_interval.start = min(new_interval.start, it->start);
	    new_interval.end = max(new_interval.end, it->end);
	    it = intervals.erase(it);
	}
    
    }
    //insert the new_interval (maybe updated several times) at the end of vector
    intervals.insert(intervals.end(), new_interval);
    return intervals;
}
