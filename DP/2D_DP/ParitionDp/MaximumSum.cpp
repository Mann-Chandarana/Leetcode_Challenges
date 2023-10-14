#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int f(int ind, vector<int> &nums, int k, int n, vector<int> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int len = 0, maxi = INT_MIN, maxAns = INT_MIN;

    for (int j = ind; j < min(j + k, n); j++)
    {
        len++;
        maxi = max(maxi, nums[j]);
        int sum = len * maxi + f(j + 1, nums, k, n, dp);
        maxAns = max(maxAns, sum);
    }

    return dp[ind] = maxAns;
}

int maximumSubarray(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, num, k, n, dp);
}

/* Tabulation */

int maximumSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> dp(n+1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;

        for (int j = ind; j < min(j + k, n); j++)
        {
            len++;
            maxi = max(maxi, nums[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }

        return dp[ind] = maxAns;
    }
    return dp[0];
}

int main()
{
    return 0;
}