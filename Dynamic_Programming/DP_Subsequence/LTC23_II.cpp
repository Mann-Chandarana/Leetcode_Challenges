/*-------- Medium -----------*/

/*- Target Sum -*/

//////// Question number 494.

#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int tar, int n)
{
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }

    if (num[0] != 0 && num[0] <= tar)
    {
        dp[0][num[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notTaken = (dp[ind - 1][target]);

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken);
        }
    }
    return dp[n - 1][tar];
}

int findTargetSumWays(vector<int> &arr, int target)
{
    int n = arr.size();
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }
    if (total_sum - target < 0 || (total_sum - target) % 2)
    {
        return 0;
    }

    return (findWays(arr, ((total_sum - target) / 2), n));
}

int main()
{
    return 0;
}