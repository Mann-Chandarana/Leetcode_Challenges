/*--------  Medium --------*/

/*- Count Ways to Group Overlapping Ranges -*/

//////// Question number 2580.

#include <bits/stdc++.h>
using namespace std;

int countWays(vector<vector<int>> &ranges)
{
    sort(ranges.begin(), ranges.end());

    int group = 1, end = -1, mod = 1e9 + 7;

    for (int i = 0; i < ranges.size(); i++)
    {
        if (end < ranges[i][0])
        {
            group = (group * 2) % mod;
        }
        end = max(end, ranges[i][1]);
    }

    return group;
}

int main()
{
    vector<vector<int>> ranges = {{6, 10}, {5, 15}};
    cout << countWays(ranges) << endl;
    return 0;
}