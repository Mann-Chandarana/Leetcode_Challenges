/*-------- Hard -----------*/

/*- Burst Ballon -*/

//////// Question number 312.

#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n ; i >= 1; i--)
    {
        for (int j = 1; j <= n ; j++)
        {
            if (i > j)
            {
                continue;
            }

            int maxi = INT_MIN;
            for (int idx = i; idx <= j; idx++)
            {
                int ans = (nums[j + 1] * nums[idx] * nums[i - 1]) + dp[i][idx - 1] + dp[idx + 1][j];
                maxi = max(maxi, ans);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

int main()
{
    vector<int> nums = {3,1,5,8};
    cout << maxCoins(nums) << endl;
    return 0;
}