#include <bits/stdc++.h>
using namespace std;

/* Using memorization */

int maximumSum(int ind, vector<int> &arr, vector<int> &dp)
{
    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    int pick = arr[ind] + maximumSum(ind - 2, arr, dp);
    int notpick = 0 + maximumSum(ind - 1, arr, dp);

    return dp[ind] = max(pick, notpick);
}

/* Using Tabulation */

int maximumSumm(int n, vector<int> arr, vector<int> dp)
{
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];

        if (i > 1)
            pick += dp[i - 2];

        int notpick = 0 + dp[i - 1];

        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}

/* Using Space optimization */

int maximumSumm(int n, vector<int> arr, vector<int> dp)
{
    int prev = arr[0], prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];

        if (i > 1)
            pick += prev2;

        int notpick = 0 + prev;

        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}

int main()
{
    return 0;
}