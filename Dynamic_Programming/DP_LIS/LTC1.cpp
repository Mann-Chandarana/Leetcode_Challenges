/*-------- Medium -----------*/

/*- Longest Increasing Subsequence -*/

//////// Question number 300.

#include <bits/stdc++.h>
using namespace std;

/* Using recursion */

int solve(vector<int> nums, int idx, int prev)
{
    if (idx == nums.size())
    {
        return 0;
    }
    int non_take = 0 + solve(nums, idx + 1, prev);
    int take = -1e8;
    if (prev == -1 || nums[idx] > nums[prev])
    {
        take = 1 + solve(nums, idx + 1, idx);
    }
    return max(non_take, take);
}

int lengthOfLIS(vector<int> &nums)
{
    return solve(nums, 0, -1);
}

/* Using Memorization */

int solve(vector<int> nums, int idx, int prev, vector<vector<int>> dp)
{
    if (idx == nums.size())
    {
        return 0;
    }
    if (dp[idx][prev + 1] != -1)
    {
        return dp[idx][prev + 1];
    }

    int non_take = 0 + solve(nums, idx + 1, prev, dp);
    int take = -1e8;
    if (prev == -1 || nums[idx] > nums[prev])
    {
        take = 1 + solve(nums, idx + 1, idx, dp);
    }
    return dp[idx][prev + 1] = max(non_take, take);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(nums, 0, -1, dp);
}

/* Using Space optimization */

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> curr(n + 1, 0), front(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int not_take = front[j + 1], take = 0;
            if (j == -1 || nums[i] > nums[j])
            {
                take = 1 + front[i + 1];
            }
            curr[j + 1] = max(not_take, take);
        }
        front = curr;
    }
    return front[0];
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}