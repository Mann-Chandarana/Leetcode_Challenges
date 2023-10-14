/*--------  Medium --------*/

/*- Check if There is a Valid Partition For The Array -*/

//////// Question number 2369.

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

bool f(int index, vector<int> &nums, vector<int> &dp)
{
    if (index < 0)
        return true;

    if (dp[index] != -1)
        return dp[index];

    bool twoEqual = false, threeEqual = false, Increasing = false;

    if (index > 0 and nums[index] == nums[index - 1])
        twoEqual = f(index - 2, nums, dp);

    if (index > 1 and nums[index] == nums[index - 1] and nums[index - 1] == nums[index - 2])
        threeEqual = f(index - 3, nums, dp);

    if (index > 1 and nums[index] == nums[index - 1] + 1 and nums[index - 1] == nums[index - 2] + 1)
        Increasing = f(index - 3, nums, dp);

    return dp[index] = twoEqual || threeEqual || Increasing;
}

bool validPartition(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n - 1, nums, dp);
}

/* Tabulation */

bool validPartition(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int index = 1; index <= n; index++)
    {
        bool twoEqual = false, threeEqual = false, Increasing = false;

        if (index > 1 and nums[index - 1] == nums[index - 2])
            twoEqual = dp[index - 2];

        if (index > 2 and nums[index - 1] == nums[index - 2] and nums[index - 2] == nums[index - 3])
            threeEqual = dp[index - 3];

        if (index > 2 and nums[index - 1] == nums[index - 2] + 1 and nums[index - 2] == nums[index - 3] + 1)
            Increasing = dp[index - 3];

        dp[index] = twoEqual || threeEqual || Increasing;
    }

    return dp[n];
}

int main()
{
    return 0;
}