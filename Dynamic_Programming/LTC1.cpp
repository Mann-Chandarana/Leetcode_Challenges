#include <bits/stdc++.h>
using namespace std;

bool solver(vector<int> &stones, int idx, int k, map<int, int> mp, vector<vector<int>> &dp)
{
    if (idx == stones.size() - 1)
    {
        return true;
    }
    bool val1 = false;
    bool val2 = false;
    bool val3 = false;

    if (dp[idx][k] != -1)
    {
        return dp[idx][k];
    }

    if (mp[stones[idx] + k - 1] > idx)
    {
        val1 = solver(stones, mp[stones[idx] + k - 1], k - 1, mp, dp);
    }
    if (mp[stones[idx] + k] > idx)
    {
        val2 = solver(stones, mp[stones[idx] + k], k, mp, dp);
    }
    if (mp[stones[idx] + k + 1] > idx)
    {
        val3 = solver(stones, mp[stones[idx] + k + 1], k + 1, mp, dp);
    }

    return dp[idx][k] = val1 || val2 || val3;
}


bool canCross(vector<int> &stones)
{
    map<int, int> mp;
    int n = stones.size();
    vector<vector<int>> dp(n, vector<int>(2 * n, -1));
    for (int i = 0; i < n; i++)
    {
        mp[stones[i]] = i;
    }
    if (stones[1] - stones[0] > 1)
    {
        return false;
    }

    return solver(stones, 1, 1, mp, dp);
}

int main()
{
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << canCross(stones) << endl;
    return 0;
}