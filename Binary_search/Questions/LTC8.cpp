/* 1351. Count Negative Numbers in a Sorted Matrix */

#include <bits/stdc++.h>
using namespace std;

/* Using Binary Search */

int countNegatives(vector<vector<int>> &grid)
{
    int n, m;
    n = grid.size();
    m = grid[0].size();
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = m - 1, ans = m;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (grid[i][mid] < 0)
            {
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;
        }
        total += m - ans;
    }
    return total;
}

/* Using upper bound */
int countNegatives(vector<vector<int>> &grid)
{
    int n, m;
    n = grid.size();
    m = grid[0].size();
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int index = upper_bound(grid[i].rbegin(), grid[i].rend(), -1) - grid[i].rbegin();
        total += index;
    }
    return total;
}

int main()
{
    vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << countNegatives(grid) << endl;
    return 0;
}