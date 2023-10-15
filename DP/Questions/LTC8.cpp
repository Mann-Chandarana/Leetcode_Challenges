#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define ll long long
#define all(v) v.begin(), v.end()

/*** Recurison + Memorization ***/

int n;

int solve(int index, int walls, vi &cost, vi &time, vector<vector<int>> &dp)
{
    if (walls <= 0)
        return 0;

    if (index >= cost.size())
        return 1e9;

    if (dp[index][walls] != -1)
        return dp[index][walls];

    int take = cost[index] + solve(index + 1, walls - 1 - time[index], cost, time, dp);
    int not_take = 0 + solve(index + 1, walls, cost, time, dp);

    return dp[index][walls] = min(take, not_take);
}

int paintWalls(vi &cost, vi &time)
{
    n = cost.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(0, n, cost, time, dp);
}

int main()
{
    vi time = {1, 1, 2, 1}, cost = {8, 7, 5, 15};

    cout << paintWalls(cost, time) << endl;

    return 0;
}