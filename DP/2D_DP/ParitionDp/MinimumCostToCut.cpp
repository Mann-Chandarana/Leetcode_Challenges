#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp1)
{
    if (i > j)
        return 0;

    if (dp1[i][j] != -1)
        return dp1[i][j];

    int mini = 1e9;

    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts, dp1) + f(k + 1, j, cuts, dp1);
        mini = min(mini, cost);
    }
    return dp1[i][j] = mini;
}

int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    vector<vector<int>> dp1(c + 1, vector<int>(c + 1, -1));

    sort(cuts.begin(), cuts.end());
    return f(1, c, cuts, dp1);
}

/* Tabulation */

int f(int n, int c, vector<int> &cuts)
{
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;
            int mini = 1e9;
            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

int main()
{
    return 0;
}