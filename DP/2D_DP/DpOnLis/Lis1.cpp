#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int f(int arr[], int n, int ind, int prev_index, vector<vector<int>> &dp)
{

    // base condition
    if (ind == n)
        return 0;

    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];

    int notTake = 0 + f(arr, n, ind + 1, prev_index, dp);

    int take = 0;

    if (prev_index == -1 || arr[ind] > arr[prev_index])
    {
        take = 1 + f(arr, n, ind + 1, ind, dp);
    }

    return dp[ind][prev_index + 1] = max(notTake, take);
}

/* Tabulation */

int f(int arr[], int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {

            int notTake = 0 + dp[ind + 1][prev_index + 1];

            int take = 0;

            if (prev_index == -1 || arr[ind] > arr[prev_index])
            {

                take = 1 + dp[ind + 1][ind + 1];
            }

            dp[ind][prev_index + 1] = max(notTake, take);
        }
    }

    return dp[0][0];
}

/* Space Optimization */

int f(int arr[], int n)
{

    vector<int> next(n + 1, 0), cur(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {
            int notTake = 0 + next[prev_index + 1];

            int take = 0;

            if (prev_index == -1 || arr[ind] > arr[prev_index])
                take = 1 + next[ind + 1];

            cur[prev_index + 1] = max(notTake, take);
        }
        next = cur;
    }

    return cur[0];
}

/* Tabulation Important method (By intution) */

int longestIncreasingSubsequence(int arr[], int n)
{

    vector<int> dp(n, 1);

    for (int i = 0; i <= n - 1; i++)
    {
        for (int prev_index = 0; prev_index <= i - 1; prev_index++)
        {
            if (arr[prev_index] < arr[i])
                dp[i] = max(dp[i], 1 + dp[prev_index]);
        }
    }

    int ans = -1;

    for (int i = 0; i <= n - 1; i++)
        ans = max(ans, dp[i]);

    return ans;
}

/* Priting Longest Increasing subsequence */

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1), hash(n, 1);

    for (int i = 0; i <= n - 1; i++)
    {
        hash[i] = i;
        for (int prev_index = 0; prev_index <= i - 1; prev_index++)
        {
            if (arr[prev_index] < arr[i] and 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    int ans = -1, lastIndex = -1;

    for (int i = 0; i <= n - 1; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    { // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    // reverse the array
    reverse(temp.begin(), temp.end());
}

int main()
{
    return 0;
}