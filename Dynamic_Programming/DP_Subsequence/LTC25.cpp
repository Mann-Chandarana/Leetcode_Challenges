/** Unbounded Knapsack **/

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
        taken = val[idx] + solve(wt, val, idx, w - wt[idx], dp);
    }
    return dp[idx][w] = max(taken, not_taken);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(wt, val, n - 1, W, dp);
}

/* Using Space optimization */

int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> cur(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
    {
        cur[i] = ((int)i / wt[0]) * val[0];
    }

    for (int ind = 1; ind < N; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {

            int notTaken = cur[cap];

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];

            cur[cap] = max(notTaken, taken);
        }
    }

    return cur[W];
}

int main()
{
    return 0;
}