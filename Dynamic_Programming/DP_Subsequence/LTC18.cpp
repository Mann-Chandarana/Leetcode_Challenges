/*-------- Hard -----------*/

/* Partition Set into 2 subset with minimum difference */

//////// Question number 2035.

#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> nums)
{
    int totSum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        totSum += nums[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (nums[0] <= totSum)
        dp[0][totSum] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totSum; target++)
        {
            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (nums[ind] <= target)
                taken = dp[ind - 1][target - nums[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    vector<int> nums = {2,-1,0,4,-2,-9};
    cout << minimumDifference(nums) << endl;
    return 0;
}