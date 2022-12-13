/*-------- Medium -----------*/

/*- Minimum Falling Path sum -*/

//////// Question number 931.

#include <bits/stdc++.h>
using namespace std;
  
/* Using memorization technique */

int path(vector<vector<int>> matrix, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0 || j >= matrix[0].size())
    {
        return 1e8;
    }

    if (i == 0)
    {
        return matrix[0][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int upper = matrix[i][j] + path(matrix, i - 1, j, dp);
    int left_diag = matrix[i][j] + path(matrix, i - 1, j - 1, dp);
    int right_diag = matrix[i][j] + path(matrix, i - 1, j + 1, dp);

    dp[i][j] = min(upper, min(left_diag, right_diag));

    return dp[i][j];
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size(), mini = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, path(matrix, n - 1, j, dp));
    }
    return mini;
}

/* Using tabular technique */

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = matrix[i][j] + dp[i - 1][j], ld = matrix[i][j], rd = matrix[i][j];
            if (j - 1 >= 0)
            {
                ld += dp[i - 1][j - 1];
            }
            else
            {
                ld += 1e8;
            }

            if (j + 1 < m)
            {
                rd += dp[i - 1][j + 1];
            }
            else
            {
                rd += 1e8;
            }

            dp[i][j] = min(u, min(ld, rd));
        }
    }
    int mini = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, dp[n - 1][j]);
    }

    return mini;
}

/* Doing space optimization in tabular form */

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> prev(m, 0), cur(m, 0);

    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = matrix[i][j] + prev[j], ld = matrix[i][j], rd = matrix[i][j];
            if (j - 1 >= 0)
            {
                ld += prev[j - 1];
            }
            else
            {
                ld += 1e8;
            }

            if (j + 1 < m)
            {
                rd += prev[j + 1];
            }
            else
            {
                rd += 1e8;
            }

            cur[j] = min(u, min(ld, rd));
        }
        prev = cur;
    }
    int mini = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, prev[j]);
    }

    return mini;
}

int main()
{
    vector<vector<int>> matrix = {{-19, 57}, {-40, -5}};
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}