/*
 *Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
 * */

#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <set>
using namespace std;


//Build a virtual tree and use bfs to find min distance
//distance add bug, refer bfs to fix
int ladder_len(std::string start, std::string end, std::set<std::string> &dict)
{
    if (start.length() != end.length()) return 0;
    if (start.compare(end) == 0) return 1;

    std::queue<std::string> bfs_queue;
    bfs_queue.push(start);
    int str_len = start.length();
    int distance = 1;
    std::string tmp(start);
    
    while (!bfs_queue.empty())
    {
        std::string node = bfs_queue.front();
        tmp = node;
        bfs_queue.pop();
        cout << "dis" << distance <<endl;
        for (int i = 0; i < str_len; i++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (node[i] != c) tmp[i] = c; else continue;
                std::set<std::string>::const_iterator got = dict.find(tmp);
                if (got != dict.end())
                {
                    if (tmp.compare(end) == 0) return distance + 1;
                    bfs_queue.push(tmp);
                    dict.erase(got);
                }
            }
            tmp = node;
        }
	++distance;
    }
    return 0;
}

void test()
{
    std::set<std::string> dict;
    dict.insert("hot"); 
    dict.insert("dot"); 
    dict.insert("dog"); 
    dict.insert("lot"); 
    dict.insert("log"); 
    int ret = ladder_len("hit", "cog", dict);
    printf("ret %d\n", ret);
}

int main()
{
    test();
}

