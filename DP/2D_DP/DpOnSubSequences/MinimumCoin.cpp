#include <bits/stdc++.h>
using namespace std;

/* Recursion and Memorization */

int f(vector<int> arr, int ind, int T, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (T % arr[0] == 0)
            return T / arr[0];
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    int notTaken = 0 + f(arr, ind - 1, T, dp);

    int taken = 1e9;
    if (arr[ind] <= T)
        taken = 1 + f(arr, ind, T - arr[ind], dp);

    return dp[ind][T] = min(notTaken, taken);
}

/* Tabulation */

int f(vector<int> arr, int ind, int T)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(T + 1, -1));

    for (int i = 0; i <= T; i++)
    {
        if (i % arr[i] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {
            int notTake = 0 + dp[ind - 1][target];

            int take = 1e9;
            if (arr[ind] <= target)
                take = 1 + dp[ind - 1][target - arr[ind]];

            dp[ind][target] = min(notTake, take);
        }
    }

    int ans = dp[n - 1][T];
    if (ans >= 1e9)
        return -1;
    return ans;
}

/* Space Optimization */

int f(vector<int> arr, int ind, int T)
{
    int n = arr.size();
    vector<int> prev(T + 1, -1);
    vector<int> curr(T + 1, -1);

    for (int i = 0; i <= T; i++)
    {
        if (i % arr[i] == 0)
            prev[i] = i / arr[0];
        else
            prev[i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {
            int notTake = 0 + prev[target];

            int take = 1e9;
            if (arr[ind] <= target)
                take = 1 + prev[target - arr[ind]];

            curr[target] = min(notTake, take);
        }
        prev = curr;
    }

    int ans = prev[T];
    if (ans >= 1e9)
        return -1;
    return ans;
}

int main()
{
    return 0;
}