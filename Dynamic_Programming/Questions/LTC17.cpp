/*-------- Medium -----------*/

/*- Minimum Number of Taps to Open to Water a Garden -*/

//////// Question number 1326.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

/* Recursion + Memorization */

int solve(int i, int maxEnd, vector<pii> &range, int &n, map<pii, int> &dp)
{
    if (i >= range.size())
        return maxEnd >= n ? 0 : 1e9;

    if (range[i].first > maxEnd)
        return 1e9;

    if (dp.find({i, maxEnd}) != dp.end())
        return dp[{i, maxEnd}];

    int not_open = solve(i + 1, maxEnd, range, n, dp);
    int open = 1 + solve(i + 1, max(maxEnd, range[i].second), range, n, dp);

    return dp[{i, maxEnd}] = min(not_open, open);
}

int minTaps(int n, vector<int> &ranges)
{
    vector<pii> range;

    for (int i = 0; i < ranges.size(); i++)
    {
        int left_range = max(0, i - ranges[i]);
        int right_range = min(n, i + ranges[i]);

        range.push_back({left_range, right_range});
    }
    sort(all(range));

    map<pii, int> dp;
    int answer = solve(0, 0, range, n, dp);

    return answer == 1e9 ? -1 : answer;
}

/* More appropriate solution */

int minTaps(int n, vector<int> &ranges)
{
    vector<int> dp(n + 1, n + 5);
    dp[0] = 0;

    for (int i = 0; i < ranges.size(); i++)
    {
        int leftReach = max(0, i - ranges[i]);

        for (int j = max(0, i - ranges[i] + 1); j <= min(i + ranges[i], n); j++)
            dp[j] = min(dp[j], dp[leftReach] + 1);
    }

    return dp[n] == n + 1 ? -1 : dp[n];
}

int main()
{
    return 0;
}