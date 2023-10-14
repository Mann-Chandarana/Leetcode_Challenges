/*-------- Medium -----------*/

/*- House Robber -*/

//////// Question number 198.

#include <bits/stdc++.h>
using namespace std;

/* Using memorization technique */

int robbing(vector<int> &nums, int idx, vector<int> dp)
{
    if (idx == 0)
    {
        return nums[0];
    }
    if (idx < 0)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int pick = nums[idx] + robbing(nums, idx - 2, dp);
    int not_pick = 0 + robbing(nums, idx - 1, dp);

    return dp[idx] = max(pick, not_pick);
}

int rob(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return robbing(nums, nums.size() - 1, dp);
}

/* Using tabular technique */

int rob(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    dp[0] = nums[0];

    int pick = INT_MIN, not_pick = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        pick = nums[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }

        not_pick = 0 + dp[i - 1];

        dp[i] = max(pick, not_pick);
    }

    return dp[n - 1];
}

/* Doing space optimization in tabular form */

int rob(vector<int> nums)
{
    int n = nums.size();

    int pick = INT_MIN, not_pick = INT_MIN, cur, prev, prev2;
    prev = nums[0];

    for (int i = 1; i < n; i++)
    {
        pick = nums[i];
        if (i > 1)
        {
            pick += prev2;
        }

        not_pick = 0 + prev;

        cur = max(pick, not_pick);

        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int main()
{
    return 0;
}