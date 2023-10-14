/*-------- Medium -----------*/

/*- Combination Sum IV -*/

//////// Question number 377.

#include <bits/stdc++.h>
using namespace std;

/**************** Recursion + Memorization ****************/

// Approach -1)

int f(int idx, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;

    if (idx >= nums.size() || target < 0)
        return 0;

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int take = f(0, nums, target - nums[idx], dp);
    int not_take = f(idx + 1, nums, target, dp);

    return dp[idx][target] = (take + not_take);
}

// Approach -2)

int f(int idx, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;

    if (idx >= nums.size() || target < 0)
        return 0;

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int result = 0;

    for (int i = idx; i < nums.size(); i++)
    {
        int take_i = f(0, nums, target - nums[i], dp);
        result += take_i;
    }

    return dp[idx][target] = result;
}

// Approach -3)

int f(vector<int> &nums, int target, vector<int> &dp)
{
    if (target == 0)
        return 1;

    if (dp[target] != -1)
        return dp[target];

    dp[target] = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= target)
            dp[target] += f(nums, target - nums[i], dp);
    }

    return dp[target];
}

int combinationSum4(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> dp(target + 1, -1);
    return f(nums, target, dp);
}

/**************** Tabulation ****************/

int combinationSum4(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<uint> dp(target + 1, 0);

    dp[0] = 1;

    for (int currTarget = 1; currTarget <= target; currTarget++)
    {
        for (auto &num : nums)
        {
            if (num <= currTarget)
                dp[currTarget] += dp[currTarget - num];
        }
    }

    return dp[target];
}

int main()
{
    vector<int> nums = {1, 2, 3};

    cout << combinationSum4(nums, 4) << endl;

    return 0;
}