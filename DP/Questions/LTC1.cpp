/*--------  Medium --------*/

/*- Unique Paths II -*/

//////// Question number 63.

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int f(int i, int j, int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return 1;

    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f(i - 1, j, m, n, obstacleGrid, dp);
    int left = f(i, j - 1, m, n, obstacleGrid, dp);

    return dp[i][j] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return f(m - 1, n - 1, m, n, obstacleGrid, dp);
}

/* Tabulation */

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;

            else if (i == 0 and j == 0)
                dp[i][j] = 1;

            else
            {
                int up = 0, left = 0;
                if (i  > 0)
                    up += dp[i - 1][j];

                if (j  > 0)
                    left += dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

/* Space Optimization */

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> prev(n, 0), curr(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                curr[j] = 0;

            else if (i == 0 and j == 0)
                curr[j] = 1;

            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up += prev[j];

                if (j > 0)
                    left += curr[j - 1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}

int main()
{
    return 0;
}