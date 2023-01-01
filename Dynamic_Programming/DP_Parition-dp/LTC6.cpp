/*-------- Medium -----------*/

/*- Partition Array for Maximum Sum -*/

//////// Question number 1043.

#include <bits/stdc++.h>
using namespace std;

/* Using Recursion + Memorizaion */

int solve(int i, vector<int> arr, int k, vector<int> dp)
{
    int n = arr.size();
    if (i == n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int len = 0, maxi = INT_MIN, ans_max = INT_MIN;

    for (int j = i; j < min(i + k, n); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int ans = maxi * len + solve(j + 1, arr, k, dp);
        ans_max = max(ans, ans_max);
    }
    return dp[i] = ans_max;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    vector<int> dp(arr.size(), -1);
    return solve(0, arr, k, dp);
}

/* Using tabulation */

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0, maxi = INT_MIN, ans_max = INT_MIN;

        for (int j = i; j < min(i + k, n); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int ans = maxi * len + dp[j + 1];
            ans_max = max(ans, ans_max);
        }
        dp[i] = ans_max;
    }

    return dp[0];
}

int main()
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    cout << maxSumAfterPartitioning(arr, 3) << endl;
    return 0;
}