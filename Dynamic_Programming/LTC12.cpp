/*--------Medium-----------*/

/*- Unique Paths II -*/

//////// Question number 63.

#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int solve(vector<vector<int>> &obstacleGrid, int m, int n, vector<vector<int>> &dp)
{
    if (m < 0 or n < 0)
    {
        return 0;
    }

    if (m == 0 and n == 0)
    {
        return 1;
    }

    if (obstacleGrid[m][n] == 1)
    {
        return 0;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    int up = solve(obstacleGrid, m - 1, n, dp);
    int right = solve(obstacleGrid, m, n - 1, dp);
    return (dp[m][n] = up + right);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(obstacleGrid, m - 1, n - 1, dp);
}

/** Using space optimization **/

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                curr[j] = 0;
                continue;
            }

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
    vector<vector<int>> obstacleGrid = {{0, 1}, {0, 0}};
    cout << uniquePathsWithObstacles(obstacleGrid);
    return 0;
}