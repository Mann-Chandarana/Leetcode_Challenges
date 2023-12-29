/*-------- Hard --------*/

/*- Minimum Difficulty of a Job Schedule -*/

//////// Question number 1335.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/******** Recursion + Memorization *******/

int solve(int index, int d, int n, vector<int> &jobDifficulty, vector<vector<int>> &dp)
{
    if (d == 1)
    {
        int maxD = INT_MIN;

        for (int i = index; i < n; i++)
            maxD = max(maxD, jobDifficulty[i]);

        return maxD;
    }

    if (dp[index][d] != -1)
        return dp[index][d];

    int result = INT_MAX, maxD = INT_MIN;
    for (int i = index; i <= n - d; i++)
    {
        maxD = max(maxD, jobDifficulty[i]);
        int ans = maxD + solve(i + 1, d - 1, n, jobDifficulty, dp);
        result = min(result, ans);
    }
    return dp[index][d] = result;
}

int minDifficulty(vector<int> &jobDifficulty, int d)
{
    int n = jobDifficulty.size();

    if (d > n)
        return -1;

    vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));

    return solve(0, d, n, jobDifficulty, dp);
}

/******** Tabulation *******/

int minDifficulty(vector<int> &jobDifficulty, int d)
{
    int n = jobDifficulty.size();

    if (d > n)
        return -1;

    vector<vector<int>> dp(n + 1, vector<int>(d + 1, 0));

    for (int index = 0; index < n; index++)
    {
        int maxD = INT_MIN;

        for (int i = index; i < n; i++)
            maxD = max(maxD, jobDifficulty[i]);

        dp[index][1] = maxD;
    }

    for (int index = n - 1; index >= 0; index--)
    {
        for (int days = 2; days <= d; days++)
        {
            int result = INT_MAX, maxD = INT_MIN;
            for (int i = index; i <= n - days; i++)
            {
                maxD = max(maxD, jobDifficulty[i]);
                int ans = maxD + solve(i + 1, days - 1, n, jobDifficulty, dp);
                result = min(result, ans);
            }
            dp[index][days] = result;
        }
    }

    return dp[0][d];
}

int main()
{
    return 0;
}