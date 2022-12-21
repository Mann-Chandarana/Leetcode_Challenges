// Max Sum without Adjacents :- geeks for geeks

// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-without-adjacents

#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int solve(int *arr, int idx, vector<int> dp)
{
    if (idx == 0)
    {
        return arr[idx];
    }

    if (idx < 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int take = arr[idx] + solve(arr, idx - 2, dp);

    int not_take = 0 + solve(arr, idx - 1, dp);

    return dp[idx] = max(take, not_take);
}

int findMaxSum(int *arr, int n)
{
    vector<int> dp(n, -1);
    return solve(arr, n - 1, dp);
}

/** Using tabulation technique **/

int findMaxSum(int *arr, int n)
{
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
        {
            take += dp[i - 2];
        }

        int not_take = dp[i - 1];

        dp[i] = max(take, not_take);
    }
    return dp[n - 1];
}

/** Using space optimization **/

int findMaxSum(int *arr, int n)
{
    int prev2 = 0, prev = 0, curr;

    for (int i = 0; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
        {
            take += prev2;
        }

        int not_take = prev;

        curr = max(take, not_take);

        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main()
{
    return 0;
}