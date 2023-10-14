#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    {
        return -1e9;
    }

    if (i == n - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }

    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }

    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int ans;
            if (j1 == j2)
            {
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            }
            else
            {
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            }
            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

/** Using tabulation technique **/

int solve(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}

int solve(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            }
            else
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= m) ||
                            (j2 + dj < 0 || j2 + dj >= m))
                        {
                            ans += -1e9;
                        }
                        else
                        {
                            ans += dp[i + 1][j1 + di][j2 + dj];
                        }
                        maxi = max(maxi, ans);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];
}

/* Using space optimization */

int solve(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> front(m, vector<int>(m, -1));
    vector<vector<int>> curr(m, vector<int>(m, -1));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                front[j1][j2] = grid[n - 1][j1];
            }
            else
            {
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= m) ||
                            (j2 + dj < 0 || j2 + dj >= m))
                        {
                            ans += -1e9;
                        }
                        else
                        {
                            ans += front[j1 + di][j2 + dj];
                        }
                        maxi = max(maxi, ans);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }

    return front[0][m - 1];
}

int main()
{
    return 0;
}