#include <bits/stdc++.h>
using namespace std;

/* Using Recursion */

int f(int i, int j, vector<vector<int>> &matrix)
{
    if (i == 0 and j == 0)
        return matrix[0][0];

    if (i < 0 or j < 0)
        return 1e9;

    int up = matrix[i][j] + f(i - 1, j, matrix);
    int down = matrix[i][j] + f(i, j - 1, matrix);

    return min(up, down);
}

/* Using memorization */

int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return matrix[0][0];

    if (i < 0 or j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + f(i - 1, j, matrix);
    int down = matrix[i][j] + f(i, j - 1, matrix);

    return dp[i][j] = min(up, down);
}

/* Using Tabulation */

int f(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j];

            else
            {
                int up = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

/* Using Space optimization */

int f(int n, int m, vector<vector<int>> &matrix)
{
    vector<int>prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int>curr(m,0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = matrix[i][j];

            else
            {
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;

                int left = matrix[i][j];
                if (j > 0)
                    left += curr[j - 1];
                else
                    left += 1e9;

                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}

int main()
{
    return 0;
}