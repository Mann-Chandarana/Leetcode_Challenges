/*--------Medium-----------*/

/*- 01 Matrix -*/

//////// Question number 542.

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0 and !visited[i][j])
            {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }

    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int distance = q.front().second;
        dist[i][j] = distance;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int row = i + drow[k];
            int col = j + dcol[k];

            if (row >= 0 and row < n and col >= 0 and col < m and !visited[row][col])
            {
                visited[row][col] = true;
                q.push({{row, col}, distance + 1});
            }
        }
    }
    return dist;
}

int main()
{
    return 0;
}