/*--------Medium-----------*/

/*- Non overlapping interval -*/

//////// Question number 435.

#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int ans = -1;
    if (intervals.size() == 0)
    {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), comp);
    int prev = intervals[0][1];

    for (vector<int> i : intervals)
    {
        if (prev > i[0])
        {
            ans++;
        }
        else
        {
            prev = i[1];
        }
    }

    cout << endl;
    return ans;
}

int main()
{
    return 0;
}