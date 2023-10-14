#include <bits/stdc++.h>
using namespace std;

/* Recursion and Memorization */

int f(vector<int> &wt, vector<int> &val, int ind, int w, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] == w)
            return 1;
        return 0;
    }

    if (dp[ind][w] != -1)
        return dp[ind][w];

    int notTaken = 0 + f(wt, val, ind - 1, w, dp);

    int taken = INT_MIN;
    if (wt[ind] <= w)
        taken = val[ind] + f(wt, val, ind - 1, w - wt[ind], dp);

    return dp[ind][w] = max(taken, notTaken);
}

/* Tabulation */

int f(vector<int> &wt, vector<int> &val, int w)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int i = wt[0]; i <= w; i++)
        dp[0][i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= w; cap++)
        {
            int notTaken = 0 + dp[ind - 1][cap];

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];

            dp[ind][cap] = max(notTaken, taken);
        }
    }

    return dp[n - 1][w];
}

/* Space Optimization */

int f(vector<int> &wt, vector<int> &val, int w)
{
    int n = wt.size();
    vector<int> prev(w + 1, 0);

    for (int i = wt[0]; i <= w; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = w; cap >= 0; cap--)
        {
            int notTaken = 0 + prev[cap];

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];

            prev[cap] = max(notTaken, taken);
        }
    }

    return prev[w];
}

int main()
{
    return 0;
}