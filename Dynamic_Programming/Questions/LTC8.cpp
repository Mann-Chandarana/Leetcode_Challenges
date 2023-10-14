/*-------- Medium -----------*/

/*- Jump Game II -*/

//////// Question number 45.

#include <bits/stdc++.h>
using namespace std;

/*** Using Recursion ***/

int answer(vector<int> nums, int index, int n)
{
    if (index == n)
        return 0;

    if (nums[index] == 0)
        return 1e8;

    int mini = INT_MAX;
    for (int i = 1; i <= nums[index]; i++)
    {
        int ans = 0;
        if (index + i <= n)
        {
            ans = 1 + answer(nums, index + i, n);
            mini = min(ans, mini);
        }
    }
    return mini;
}

int jump(vector<int> &nums)
{
    int n = nums.size() - 1;
    return answer(nums, 0, n);
}

/*** Using Memorization ***/

int answer(vector<int> nums, int index, int n, vector<int> &dp)
{
    if (index == n)
        return 0;

    if (nums[index] == 0)
        return 1e8;

    if (dp[index] != -1)
        return dp[index];

    int mini = INT_MAX;
    for (int i = 1; i <= nums[index]; i++)
    {
        int ans = 0;
        if (index + i <= n)
        {
            ans = 1 + answer(nums, index + i, n, dp);
            mini = min(ans, mini);
        }
    }
    return dp[index] = mini;
}

int jump(vector<int> &nums)
{
    int n = nums.size() - 1;
    vector<int> dp(n + 1, -1);
    return answer(nums, 0, n, dp);
}

/*** Using tabulation ****/

int jump(vector<int> &nums)
{
    int n = nums.size() - 1;
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    for (int i = 0; i <= n; i++)
        if (nums[i] == 0)
            dp[i] = 1e8;

    for (int index = n - 1; index >= 0; index--)
    {
        if (nums[index] != 0)
        {
            int mini = INT_MAX;
            for (int i = 1; i <= nums[index]; i++)
            {
                int ans = 0;
                if (index + i <= n)
                {
                    ans = 1 + dp[index + i];
                    mini = min(ans, mini);
                }
            }
            dp[index] = mini;
        }
    }

    return dp[0];
}

/*** Using Greedy ****/

int jump(vector<int> &nums)
{
    int curReach = 0, currMax = 0, jumps = 0, n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        if (i + nums[i] > currMax)
            currMax = i + nums[i];

        if (i == curReach)
        {
            jumps++;
            curReach = currMax;
        }
    }

    return jumps;
}

int main()
{
    vector<int> nums = {2, 1};
    cout << jump(nums) << endl;
    return 0;
}