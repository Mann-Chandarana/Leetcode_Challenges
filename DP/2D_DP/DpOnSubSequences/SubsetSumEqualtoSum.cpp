#include <bits/stdc++.h>
using namespace std;

/* Recursion and Memorization */

int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = f(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = f(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = taken || notTaken;
}

/* Tabulation */

int f(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int index = 0; index < n; index++)
        dp[index][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int index = 0; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[index - 1][target];

            bool taken = false;
            if (arr[index] <= target)
                taken = dp[index - 1][target - arr[index]];

            dp[index][target] = taken || notTaken;
        }
    }
    return dp[n - 1][k];
}

/* Space Optimization */

int f(int n, int k, vector<int> &arr)
{
    vector<int> prev(k + 1, 0);

    prev[0] = true;

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int index = 0; index < n; index++)
    {
        vector<int> curr(k + 1, 0);
        curr[0] = true;
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = prev[target];

            bool taken = false;
            if (arr[index] <= target)
                taken = prev[target - arr[index]];

            curr[target] = taken || notTaken;
        }
        prev = curr;
    }
    return prev[k];
}

int main()
{
    return 0;
}