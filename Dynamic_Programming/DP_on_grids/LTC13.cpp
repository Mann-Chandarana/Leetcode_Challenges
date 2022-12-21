/*--------Medium-----------*/

/*- Minimum Path Sum -*/

//////// Question number 64.

#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int solve(vector<vector<int>> grid, int i, int j, vector<vector<int>> dp)
{
    if (i < 0 or j < 0)
    {
        return 1e8;
    }
    if (i == 0 and j == 0)
    {
        return grid[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = grid[i][j] + solve(grid, i - 1, j, dp);
    int left = grid[i][j] + solve(grid, i, j - 1, dp);

    return dp[i][j] = min(up, left);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(grid, m - 1, n - 1,dp);
}

/** Using tabulation technique **/

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = 1e8, left = 1e8;
            if (i > 0)
            {
                up = grid[i][j] + dp[i - 1][j];
            }
            if (j > 0)
            {
                left = grid[i][j] + dp[i][j - 1];
            }
            dp[i][j] = min(up, left);
        }
    }
    return dp[m - 1][n - 1];
}

/** Using space optimization **/

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                curr[j] = grid[i][j];
                continue;
            }
            int up = 1e8, left = 1e8;
            if (i > 0)
            {
                up = grid[i][j] + prev[j];
            }
            if (j > 0)
            {
                left = grid[i][j] + curr[j - 1];
            }
            curr[j] = min(up, left);
        }
        prev = curr;
    }
    return prev[n - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    return 0;
}