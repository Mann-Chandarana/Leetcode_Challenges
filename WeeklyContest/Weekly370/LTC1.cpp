/* 100115. Find Champion I */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int findChampion(vector<vector<int>> &grid)
{
    int teams = grid.size();

    for (int i = 0; i < teams; i++)
    {
        int count = 0;
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
                count++;
        }
        if (count == (teams - 1))
            return i;
    }
    return -1;
}

int main()
{
    return 0;
}