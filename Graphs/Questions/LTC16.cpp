#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> answer(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
                q.push({{i, j}, 0});
        }
    }

    vector<int> dirx = {0, 1, 0, -1};
    vector<int> diry = {-1, 0, 1, 0};

    while (!q.empty())
    {
        int x = q.front().first.first, y = q.front().first.second, dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dirx[i], newy = y + diry[i];

            if (newx >= 0 and newx < m and newy >= 0 and newy < n)
            {
                if (mat[newx][newy] == 1)
                {
                    answer[newx][newy] = dist + 1;
                    q.push({{newx, newy}, dist + 1});
                    mat[newx][newy] = 2; // To mark it visited
                }
            }
        }
    }
    return answer;
}

int main()
{
    return 0;
}