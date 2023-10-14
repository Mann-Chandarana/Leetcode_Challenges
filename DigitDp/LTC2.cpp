/*--------  Hard --------*/

/*- Count Stepping Numbers in Range -*/

//////// Question number 2801.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1e9 + 7;

int dp[101][2][2][11];

ll solve(string &nums, int pos = 0, bool tight = 1, bool leading = 1, int previous = -1)
{
    if (pos == nums.size())
        return 1;

    if (dp[pos][tight][leading][previous + 1] != -1)
        return dp[pos][tight][leading][previous + 1];

    ll hi = tight ? nums[pos] - '0' : 9;

    ll count = 0;

    for (int idx = 0; idx <= hi; idx++)
    {
        if (previous != -1 and !leading)
        {
            if (abs(previous - idx) == 1)
                count = (count + (solve(nums, pos + 1, (tight && (idx == hi)), (leading && (idx == 0)), idx) % MOD)) % MOD;
            continue;
        }
        count = (count + (solve(nums, pos + 1, tight && (idx == hi), leading && (idx == 0), idx) % MOD)) % MOD;
    }

    return (dp[pos][tight][leading][previous + 1] = count);
}

int countSteppingNumbers(string low, string high)
{
    memset(dp, -1, sizeof(dp));
    ll a = solve(low);
    int valid = 1;
    for (int i = 1; i < low.size(); i++)
    {
        if (abs(low[i] - low[i - 1]) != 1)
        {
            valid = 0;
            break;
        }
    }
    a -= valid;
    memset(dp, -1, sizeof(dp));
    ll b = solve(high);

    ll ans = (b - a + MOD) % MOD;
    return ans;
}

int main()
{
    return 0;
}