/* 733. Flood Fill */

#include <bits/stdc++.h>
using namespace std;

/* Using DFS traversal */

void dfs(int row, int col, vector<vector<int>> &ans,
         vector<vector<int>> &image, int newColor, int delRow[], int delCol[],
         int iniColor)
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image,
                              int sr, int sc, int newColor)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    return ans;
}

/* Using BFS traversal  */

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size(), m = image[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, 1, 0, -1};

    int required = image[sr][sc];

    q.push({sr, sc});
    image[sr][sc] = color;
    visited[sr][sc] = true;

    while (!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int row = i + drow[k], col = j + dcol[k];

            if (row >= 0 and row < n and col >= 0 and col < m and image[row][col] == required and !visited[row][col])
            {
                visited[row][col] = true;
                image[row][col] = color;
                q.push({row, col});
            }
        }
    }
    return image;
}

int main()
{
    return 0;
}