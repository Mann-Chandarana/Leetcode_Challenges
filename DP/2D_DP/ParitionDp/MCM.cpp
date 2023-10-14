#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int n;
vector<vector<int>> dp(n, vector<int>(n, -1));

int f(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr) + f(k + 1, j, arr);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

/* Tabulation */

int f(int n, vector<int> arr)
{
    vector<vector<int>> dp1(n, vector<int>(n, 0));

    for (int i = 1; i < n; i++)
        dp1[i][i] = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp1[i][k] + dp1[k + 1][j];
                mini = min(mini, steps);
            }
            dp1[i][j] = mini;
        }
    }
    return dp1[1][n - 1];
}

int main()
{
    return 0;
}