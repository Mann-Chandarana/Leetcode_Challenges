#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
        return 0;

    if (i == (m - 1) and j == (n - 1))
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = solve(i + 1, j, m, n, dp);

    int right = solve(i, j + 1, m, n, dp);

    return dp[i][j] = (down + right);
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve(0, 0, m, n, dp);
}

/* Tabulation */

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    dp[m - 1][n - 1] = 1;

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 and j == n - 1)
                continue;
                
            int down = dp[i + 1][j];

            int right = dp[i][j + 1];

            dp[i][j] = (down + right);
        }
    }

    return dp[0][0];
}

int main()
{
    cout << uniquePaths(3, 7) << endl;
    return 0;
}