/*--------  Medium --------*/

/*- Check Knight Tour Configuration -*/

//////// Question number 2596.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec = {{1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}};

bool positive_step(vector<vector<int>> grid, int i, int j, int n, int step)
{
    if (grid[i][j] == step)
        return true;

    return false;
}

bool valid(vector<vector<int>> grid, int step, int n, vector<vector<bool>> &validgrid, int x, int y)
{
    if (step == (n * n))
        return true;

    for (int i = 0; i < vec.size(); i++)
    {
        int idx = x + vec[i][0];
        int idy = y + vec[i][1];

        if (idx >= 0 and idy >= 0 and idx < n and idy < n and !validgrid[idx][idy] and grid[idx][idy] == step)
        {
            validgrid[idx][idy] = true;
            if (valid(grid, step + 1, n, validgrid, idx, idy))
                return true;

            validgrid[idx][idy] = false;
        }
    }
    return false;
}

bool checkValidGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> validgrid(n, vector<bool>(n, false));
    return valid(grid, 1, n, validgrid, 0, 0);
}

int main()
{
    vector<vector<int>> grid = {{0, 3, 6}, {5, 8, 1}, {2, 7, 4}};
    cout << checkValidGrid(grid) << endl;
    return 0;
}