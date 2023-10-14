/*--------Hard-----------*/

/*- Unique Paths III -*/

//////// Question number 980.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, int x, int y, int &zero)
{
    if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] == -1)
    {
        return 0;
    }
    if (grid[x][y] == 2)
    {
        if (zero == -1)
        {
            return 1;
        }
        return 0;
    }

    grid[x][y] = -1;
    zero--;

    int answer = solve(grid, x + 1, y, zero) + solve(grid, x, y + 1, zero) + solve(grid, x - 1, y, zero) + solve(grid, x, y - 1, zero);

    grid[x][y] = 0;
    zero++;

    return answer;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    int zero = 0;
    int x = 0, y = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                zero++;
            }
            if (grid[i][j] == 1)
            {
                x = i, y = j;
            }
        }
    }
    cout<<zero<<endl;
    return solve(grid, x, y, zero);
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    cout << uniquePathsIII(grid) << endl;
    return 0;
}