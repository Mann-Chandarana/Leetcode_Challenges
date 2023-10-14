/*-------- Medium -----------*/

/*- Non-overlapping Intervals -*/

//////// Question number 435.

#include <bits/stdc++.h>
using namespace std;

bool comparotor(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),comparotor);

    int previous = intervals[0][1];
    int answer = 0;

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < previous)
            answer++;

        else
            previous = intervals[i][1];
    }
    return answer;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}