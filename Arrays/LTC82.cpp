/*-------- Medium -----------*/

/*- Merge Intervals -*/

//////// Question number 56.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> answer;
    vector<int> previous(2);
    previous[0] = intervals[0][0];
    previous[1] = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > previous[1])
        {
            answer.push_back(previous);
            previous = intervals[i];
        }
        else
        {
            previous[1] = max(intervals[i][1], previous[1]);
        }
    }
    answer.push_back(previous);

    return answer;
}

int main()
{
    return 0;
}