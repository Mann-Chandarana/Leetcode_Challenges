/*-------- Medium -----------*/

/*- Insert Interval -*/

//////// Question number 57.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> answer;

    int i = 0, n = intervals.size();

    while (i < n and intervals[i][1] < newInterval[0])
    {
        answer.push_back(intervals[i]);
        i++;
    }

    while (i < n and newInterval[1] >= intervals[i][0])
    {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    answer.push_back(newInterval);

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