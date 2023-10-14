/** 0/1 Knapsack :- geeks for geeks **/

// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=0-1-knapsack-problem0945

#include <bits/stdc++.h>
using namespace std;

/* Using Memorization */

int solve(int wt[], int val[], int idx, int w, vector<vector<int>> dp)
{
    if (idx == 0)
    {
        if (wt[0] <= w)
        {
            return val[0];
        }
        return 0;
    }
    if (dp[idx][w] != -1)
    {
        return dp[idx][w];
    }

    int not_taken = 0 + solve(wt, val, idx - 1, w, dp);
    int taken = INT_MIN;

    if (wt[idx] <= w)
    {
        taken = val[idx] + solve(wt, val, idx - 1, w - wt[idx], dp);
    }
    return dp[idx][w] = max(taken, not_taken);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(wt, val, n - 1, W, dp);
}

/* Using Tabulation */

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int w = 0; w <= W; w++)
        {
            int not_taken = 0 + dp[idx - 1][w];

            int taken = INT_MIN;

            if (wt[idx] <= w)
            {
                taken = val[idx] + dp[idx - 1][w - wt[idx]];
            }
            dp[idx][w] = max(taken, not_taken);
        }
    }
    return dp[n - 1][W];
}

/* Using Space optimization */

int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> curr(W + 1, 0), prev(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = val[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int w = 0; w <= W; w++)
        {
            int not_taken = 0 + prev[w];

            int taken = INT_MIN;

            if (wt[idx] <= w)
            {
                taken = val[idx] + prev[w - wt[idx]];
            }
            curr[w] = max(taken, not_taken);
        }
        prev = curr;
    }
    return prev[W];
}

int main()
{
    int wt[] = {4, 5, 1}, val[] = {1, 2, 3};
    cout << knapSack(4, wt, val, 3) << endl;
    return 0;
}