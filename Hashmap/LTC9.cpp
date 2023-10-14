/*-------- Medium -----------*/

/*- Equal Row and Column Pairs -*/

//////// Question number 2352.

#include <bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>> &grid)
{
    int n = grid.size();
    map<vector<int>, int> mp;

    for (int i = 0; i < n; i++)
        mp[grid[i]]++;

    int count = 0;
    for (int c = 0; c < n; c++)
    {
        vector<int> temp;

        for (int r = 0; r < n; r++)
            temp.push_back(grid[r][c]);

        count += mp[temp];
    }
    return count;
}

int main()
{
    return 0;
}