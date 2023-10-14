/*--------Medium-----------*/

/*- Number of Islands -*/

//////// Question number 200.

#include <bits/stdc++.h>
using namespace std;

void bfs_Traversal(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dirx[i];
            int ncol = col + diry[i];

            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == '1' and !visited[nrow][ncol])
            {
                visited[nrow][ncol] = true;
                q.push({nrow, ncol});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int v = grid.size();
    int islands = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' and !visited[i][j])
            {
                islands++;
                bfs_Traversal(i, j, visited, grid);
            }
        }
    }
    return islands;
}

int main()
{
    return 0;
}