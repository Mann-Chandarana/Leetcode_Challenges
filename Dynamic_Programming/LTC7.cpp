// Frog jump with k jumps :- geeks for geeks

// https://practice.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int solve(vector<int> &height, int n, int k, vector<int> dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int mini = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int value = abs(height[n] - height[n - i]) + solve(height, n - i, k, dp);
            mini = min(mini, value);
        }
    }
    return dp[n] = mini;
}

int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n, -1);
    return solve(height, n - 1, k, dp);
}

/** Using tabulation technique **/

int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int value = abs(height[i] - height[i - j]) + dp[i - j];
                mini = min(mini, value);
            }
        }
        dp[i] = mini;
    }
    return dp[n - 1];
}

/** Using space optimization **/

int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int value = abs(height[i] - height[i - j]) + dp[i - j];
                mini = min(mini, value);
            }
        }
        dp[i] = mini;
    }
    return dp[n - 1];
}

int main()
{
    return 0;
}