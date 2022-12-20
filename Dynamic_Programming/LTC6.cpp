// Frog jump (dp-3) :- geeks for geeks

// https://practice.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int solve(vector<int> height, int n, vector<int> dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int one_step = solve(height, n - 1, dp) + abs(height[n] - height[n - 1]), two_step = 1e8;
    if (n > 1)
    {
        two_step = solve(height, n - 2, dp) + abs(height[n] - height[n - 2]);
    }

    return dp[n] = min(one_step, two_step);
}

int minimumEnergy(vector<int> &height, int n)
{
    vector<int> dp(n, -1);
    return solve(height, n - 1, dp);
}

/** Using tabulation technique **/

int minimumEnergy(vector<int> &height, int n)
{
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int one_step = dp[i - 1] + abs(height[i] - height[i - 1]);
        int two_step = 1e8;
        if (i > 1)
        {
            two_step = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(one_step, two_step);
    }

    return dp[n - 1];
}

/** Using space optimization **/

int minimumEnergy(vector<int> &height, int n)
{
    int prev = 0, prev2 = 0, curr;

    for (int i = 1; i < n; i++)
    {
        int one_step = prev + abs(height[i] - height[i - 1]);
        int two_step = 1e8;
        if (i > 1)
        {
            two_step = prev2 + abs(height[i] - height[i - 2]);
        }
        curr = min(one_step, two_step);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    return 0;
}