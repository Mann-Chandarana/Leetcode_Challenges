// Subset sum Problem :- geeks for geeks 

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sum-problem-1611555638

#include <bits/stdc++.h>
using namespace std;

/* Two changes variable are changing
1) idx
2) sum
so we will require 2-D matrix
*/

/* Using Memorization */

bool solve(int idx, vector<int> arr, int sum, vector<vector<int>> dp)
{
    if (sum == 0)
    {
        return true;
    }

    if (idx == 0)
    {
        if (arr[idx] == sum)
        {
            return true;
        }
        return false;
    }

    if (dp[idx][sum] != -1)
    {
        return dp[idx][sum];
    }

    bool pick = false;
    if (arr[idx] <= sum)
    {
        pick = solve(idx - 1, arr, sum - arr[idx], dp);
    }
    bool non_pick = solve(idx - 1, arr, sum, dp);

    return dp[idx][sum] = (pick || non_pick);
}

bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve(n - 1, arr, sum, dp);
}

/* Using Tabulation */

bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool pick = false;
            if (arr[i] <= j)
            {
                pick = dp[i - 1][j - arr[i]];
            }
            bool non_pick = dp[i - 1][j];
            dp[i][j] = (pick || non_pick);
        }
    }

    return dp[n - 1][sum];
}

/* Using Space optimization */

bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    vector<bool> curr(sum + 1, false), prev(sum + 1, false);

    for (int i = 0; i < n; i++)
    {
        prev[0] = true;
    }
    if (arr[0] <= sum)
    {
        prev[arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool pick = false;
            if (arr[i] <= j)
            {
                pick = prev[j - arr[i]];
            }
            bool non_pick = prev[j];
            curr[j] = (pick || non_pick);
        }
        prev = curr;
    }

    return prev[sum];
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    cout << isSubsetSum(arr, 30) << endl;
    return 0;
}