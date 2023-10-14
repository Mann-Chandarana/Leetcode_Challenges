/*--------Medium-----------*/

/*- Unique Paths -*/

//////// Question number 62.

#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int solve(int m, int n, vector<vector<int>> &dp)
{
    if (m < 0 or n < 0)
    {
        return 0;
    }

    if (m == 0 and n == 0)
    {
        return 1;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    int up = solve(m - 1, n, dp);
    int right = solve(m, n - 1, dp);
    return (dp[m][n] = up + right);
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int value = solve(m - 1, n - 1, dp);
    return value;
}

/** Using tabulation technique **/

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    dp[1][1] = 1;

    for (int i = 1; i <=m; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i ==1  and j == 1)
            {
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

/** Using space optimization **/

int uniquePaths(int m, int n)
{
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                curr[j] = 1;
                continue;
            }
            int up = 0, right = 0;

            if (i > 0)
            {
                up = prev[j];
            }
            if (j > 0)
            {
                right = curr[j - 1];
            }

            curr[j] = up + right;
        }
        prev = curr;
    }
    return prev[n - 1];
}

int main()
{
    cout << uniquePaths(3, 7) << endl;
    return 0;
}