/*--------Medium-----------*/

/*- Shortest Path in Binary Matrix -*/

//////// Question number 1091.

#include <bits/stdc++.h>
using namespace std;

/* Using Dijkstra's Algorithm */

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> distance(n, vector<int>(n, 1e9));

    if (grid[0][0] == 0 && n == 1)
        return 1;

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    queue<pair<int, pair<int, int>>> q;

    q.push({0, {0, 0}});

    while (!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dis = q.front().first;
        q.pop();

        if (x == n - 1 and y == n - 1)
            return distance[x][y] + 1;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int dx = x + i, dy = y + j;
                if (dx >= 0 and dx < n and dy >= 0 and dy < n and grid[dx][dy] == 0 and dis + 1 < distance[dx][dy])
                {
                    distance[dx][dy] = dis + 1;
                    q.push({distance[dx][dy], {dx, dy}});
                }
            }
        }
    }

    return -1;
}

/* Using BFS */

bool isValid(int i, int j, vector<vector<int>> &grid)
{
    return i >= 0 and i < grid.size() and j >= 0 and j < grid.size() and grid[i][j] == 0;
}

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid[0][0])
        return -1;

    int res;

    queue<pair<int, int>> q1;
    q1.push({0, 0});
    grid[0][0] = 2;

    int n = grid.size();

    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {-1, -1}, {+1, -1}, {-1, +1}, {+1, +1}};

    while (!q1.empty())
    {
        int size = q1.size();
        res++;

        while (size--)
        {
            int i = q1.front().first;
            int j = q1.front().second;
            q1.pop();

            if (i == n - 1 and j == n - 1)
                return res;

            for (auto dir : dirc)
            {
                int newX = i + dir.first;
                int newY = j + dir.second;

                if (isValid(newX, newY, grid))
                {
                    grid[newX][newY] = 2;
                    q1.push({newX, newY});
                }
            }
        }
    }

    return -1;
}

int main()
{
    return 0;
}