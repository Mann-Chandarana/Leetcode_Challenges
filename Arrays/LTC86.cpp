/*-------- Hard -----------*/

/*- Perfect rectangle -*/

//////// Question number 391.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> answer;

    int i = 0, n = intervals.size();
    
    /* New interval after this interval */

    while (i < n and intervals[i][1] < newInterval[0])
    {
        answer.push_back(intervals[i]);
        i++;
    }

    /* Overlapping of the intervals */

    while (i < n and newInterval[1] >= intervals[i][0])
    {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    answer.push_back(newInterval);
   
    /* After inserting new interval we have to insert the remainig intervals */

    while (i < n)
    {
        answer.push_back(intervals[i]);
        i++;
    }
    return answer;
}

int main()
{
    return 0;
}