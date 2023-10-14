/*-------- Hard -----------*/

/*- Number of Increasing Paths in a Grid -*/

//////// Question number 2328.

#include <bits/stdc++.h>
using namespace std;

vector<int> dirx = {-1, 0, 1, 0}, diry = {0, -1, 0, 1};

long long mod = 1e9 + 7;

int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    int answer = 1;

    for (int z = 0; z < 4; z++)
    {
        int dx = i + dirx[z];
        int dy = j + diry[z];

        if (((dx >= 0 and dx < grid.size()) and (dy >= 0 and dy < grid[0].size())) and grid[dx][dy] > grid[i][j])
        {
            answer = ((answer % mod + dfs(grid, dx, dy, dp)) % mod) % mod;
        }
    }
    return dp[i][j] = answer;
}

int countPaths(vector<vector<int>> &grid)
{
    long long result = 0;
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
            result = ((result % mod + dfs(grid, i, j, dp)) % mod) % mod;
    }

    return result % mod;
}

int main()
{
    return 0;
}