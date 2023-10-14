/*--------  Medium --------*/

/*- As Far from Land as Possible -*/

//////// Question number 1162.

#include <bits/stdc++.h>
using namespace std;

/**** Using BFS ****/

// Here we have used the concept of multiple head BFS

int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                grid[i][j] = 2;
                q.push({i, j});
            }
        }
    }
    
    if (q.size() == 0 or q.size() == n * m )
        return -1;

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ans = 0;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (auto element : dirs)
            {
                int new_i = x + element.first, new_j = y + element.second;
                if ((new_i >= 0 and new_i < n) and (new_j >= 0 and new_j < n) and grid[new_i][new_j] == 0)
                {
                    q.push({new_i, new_j});
                    grid[new_i][new_j] = 2;
                }
            }
        }
        ans++;
    }

    return ans - 1;
}

/**** Using iteration ****/

int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<pair<int, int>> land_coordinates;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                land_coordinates.push_back({i, j});
        }
    }
    if (land_coordinates.size() == 0)
        return -1;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                int mini = INT_MAX;
                for (auto element : land_coordinates)
                {
                    int x = element.first, y = element.second;
                    int dis = abs(i - x) + abs(j - y);
                    if (dis <= maxi)
                    {
                        mini = dis;
                        break;
                    }
                    mini = min(mini, dis);
                }
                maxi = max(maxi, mini);
            }
        }
    }
    return maxi != INT_MIN ? maxi : -1;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
    cout << maxDistance(grid) << endl;
    return 0;
}