//////// Question number 2373.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> solution(n - 2, vector<int>(n - 2, 0));
    int looping_factor = (n - 2) * (n - 2);
    int start_x = 0, start_y = 0;
    for (int i = 0; i < looping_factor; i++)
    {
        int maxi = INT_MIN;
        for (int j = start_x; j < start_x + 3; j++)
        {
            for (int k = start_y; k < start_y + 3; k++)
            {
                maxi = max(maxi, grid[j][k]);
            }
        }
        solution[start_x][start_y] = maxi;
        if (start_y + 3 < n)
        {
            start_y++;
        }
        else
        {
            start_x++;
            start_y = 0;
        }
    }
    return solution;
}

int main()
{
    vector<vector<int>> grid = {{1,1,1,1,1}, {1,1,1,1,1}, {1,1,2,1,1}, {1,1,1,1,1},{1,1,1,1,1}};
    grid = largestLocal(grid);

    for (auto x : grid)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}