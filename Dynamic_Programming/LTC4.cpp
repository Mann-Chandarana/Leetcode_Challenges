/*-------- Medium -----------*/

/*- Minimum Falling Path Sum -*/

//////// Question number 931.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/** Recursion + Memorization **/

int fn(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int minSum = INT_MAX;

    for (int shift = -1; shift <= 1; shift++)
    {
        if (j + shift >= 0 and j + shift < m)
            minSum = min(minSum, matrix[i][j] + fn(i + 1, j + shift, n, m, matrix, dp));
    }
    return dp[i][j] = minSum;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    int mini = INT_MAX;

    for (int j = 0; j < m; j++)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        mini = min(mini, fn(0, j, n, m, matrix, dp));
    }
    return mini;
}

/** Tabulation **/

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    int mini = INT_MAX;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
        dp[n - 1][j] = matrix[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            int minSum = INT_MAX;

            for (int shift = -1; shift <= 1; shift++)
            {
                if (j + shift >= 0 and j + shift < m)
                    minSum = min(minSum, matrix[i][j] + dp[i + 1][j + shift]);
            }
            dp[i][j] = minSum;
        }
    }

    for (int j = 0; j < m; j++)
        mini = min(mini, dp[0][j]);

    return mini;
}

/** Space Optimization solution **/

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    int mini = INT_MAX;

    vector<int> next(m, 0), curr(m, 0);

    for (int j = 0; j < m; j++)
        next[j] = matrix[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            int minSum = INT_MAX;

            for (int shift = -1; shift <= 1; shift++)
            {
                if (j + shift >= 0 and j + shift < m)
                    minSum = min(minSum, matrix[i][j] + next[j + shift]);
            }
            curr[j] = minSum;
        }
        next = curr;
    }

    for (int j = 0; j < m; j++)
        mini = min(mini, next[j]);

    return mini;
}

/** Space Optimization solution - 2) **/

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int col = 0; col < m; col++)
        dp[0][col] = matrix[0][col];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dp[i][j] = matrix[i][j] + min({(dp[i - 1][j]), (dp[i - 1][max(0, j - 1)]), (dp[i - 1][min(m - 1, j + 1)])});
    }

    return *min_element(all(dp[n - 1]));
}

int main()
{
    return 0;
}