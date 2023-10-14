/*--------Medium-----------*/

//////// Question number 807.

#include <bits/stdc++.h>
using namespace std;

/***************** Time complexity is O(N^2) ********************/

int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> row(n, 0);
    vector<int> col(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            row[i] = max(row[i], grid[i][j]);
            col[i] = max(col[i], grid[j][i]);
        }
    }

    int height = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            height += (min(row[i], col[j]) - grid[i][j]);
        }
    }

    return height;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << maxIncreaseKeepingSkyline(grid) << endl;

    return 0;
}