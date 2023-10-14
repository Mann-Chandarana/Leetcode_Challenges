/*--------Medium-----------*/

/*- Number of Enclaves -*/

//////// Question number 1020.

#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>> &grid)
{
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1};

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, false));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
    }

    while (!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int row = i + delrow[k], col = j + delcol[k];
            if (row >= 0 and row < n and col >= 0 and col < m and grid[row][col] == 1 and !visited[row][col])
            {
                visited[row][col] = true;
                q.push({row, col});
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] and grid[i][j] == 1)
                count++;
        }
    }
    return count;
}

int main()
{
    return 0;
}