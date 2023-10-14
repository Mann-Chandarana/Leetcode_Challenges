/* Geeks for Geeks :- Number of Distinct IslandsNumber of Distinct Islands */

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid, int delrow[], int delcol[], vector<pair<int, int>> &vec, int row0, int col0)
{
    visited[i][j] = true;
    int n = grid.size(), m = grid[0].size();
    vec.push_back({i - row0, j - col0});

    for (int k = 0; k < 4; k++)
    {
        int row = i + delrow[k], col = j + delcol[k];

        if (row >= 0 and row < n and col >= 0 and col < m and grid[row][col] == 1 and !visited[row][col])
            dfs(row, col, visited, grid, delrow, delcol, vec, row0, col0);
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 and !visited[i][j])
            {
                vector<pair<int, int>> vec;
                dfs(i, j, visited, grid, delrow, delcol, vec, i, j);

                st.insert(vec);
            }
        }
    }

    return st.size();
}

int main()
{
    return 0;
}