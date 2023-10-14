/*-------- Medium -----------*/

/*- Longest Arithmetic Subsequence-*/

//////// Question number 1027.

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int solve(vector<int> nums, int i, int diff, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;

    if (dp[i][diff + 501] != -1)
        return dp[i][diff + 501];

    int ans = 0;

    for (int k = i - 1; k >= 0; k--)
    {
        if (nums[i] - nums[k] == diff)
            ans = max(ans, 1 + solve(nums, k, diff, dp));
    }
    return dp[i][diff + 501] = ans;
}

int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(1001, -1));

    if (n <= 2)
        return n;

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            result = max(result, 2 + solve(nums, i, nums[j] - nums[i], dp));
        }
    }

    return result;
}

/* Bottom up */

int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();

    if (n <= 2)
        return n;
    vector<vector<int>> dp(n, vector<int>(1001, 0));

    int result = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j] + 500; // to avoid negative difference

            dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;

            result = max(result, dp[i][diff]);
        }
    }
    return result;
}

int main()
{
    return 0;
}