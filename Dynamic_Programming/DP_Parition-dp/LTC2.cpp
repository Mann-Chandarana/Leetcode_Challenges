/*-------- Hard -----------*/

/*- Minimum Cost to Cut a Stick -*/

//////// Question number 1547.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &cuts, int i, int j, vector<vector<int>> dp)
{
    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mini = INT_MAX;
    for (int idx = i; idx <= j; idx++)
    {
        int ans = cuts[j + 1] - cuts[i - 1] + solve(cuts, i, idx - 1, dp) + solve(cuts, idx + 1, j, dp);
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}

int minCost(int length, vector<int> &cuts)
{
    cuts.push_back(length);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int c = cuts.size();
    vector<vector<int>> dp(c, vector<int>(c, -1));

    return solve(cuts, 1, c - 2, dp);
}

int minCost(int length, vector<int> &cuts)
{
    cuts.push_back(length);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int c = cuts.size();
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i>j)
            {
                continue;
            }
            
            int mini = INT_MAX;
            for (int idx = i; idx <= j; idx++)
            {
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][idx - 1] + dp[idx + 1][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c-2];
}

int main()
{
    vector<int> cuts = {3, 5, 1, 4};
    cout << minCost(7, cuts) << endl;
    return 0;
}