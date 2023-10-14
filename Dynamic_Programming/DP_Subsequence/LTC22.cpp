/*-------- Medium -----------*/

/*- Coin Change -*/

//////// Question number 332.

#include <bits/stdc++.h>
using namespace std;

/* Using Memorization */

int solve(vector<int> coins, int amount, int idx, vector<vector<int>> dp)
{
    if (idx == 0 || amount == 0)
    {
        if (amount % coins[0] == 0)
        {
            return (amount / coins[0]);
        }
        return 1e9;
    }

    if (dp[idx][amount] != -1)
    {
        return dp[idx][amount];
    }

    int not_taken = 0 + solve(coins, amount, idx - 1, dp);

    int taken = 1e9;

    if (coins[idx] <= amount)
    {
        taken = 1 + solve(coins, amount - coins[idx], idx, dp);
    }

    return dp[idx][amount] = min(taken, not_taken);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int val = solve(coins, amount, n - 1, dp);
    if (val == 1e9)
    {
        return -1;
    }
    return val;
}

/* Using Tabulation */

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = (i / coins[0]);
        }
        else
        {
            dp[0][i] = 1e9;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int non_taken = 0 + dp[i - 1][j];

            int taken = 1e9;
            if (coins[i] <= j)
            {
                taken = 1 + dp[i][j - coins[i]];
            }
            dp[i][j] = min(taken, non_taken);
        }
    }

    int ans = dp[n - 1][amount];
    if (ans >= 1e9)
    {
        return -1;
    }
    return ans;
}

/* Using Space optimization */

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            prev[i] = (i / coins[0]);
        }
        else
        {
            prev[i] = 1e9;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int non_taken = 0 + prev[j];

            int taken = 1e9;
            if (coins[i] <= j)
            {
                taken = 1 + curr[j - coins[i]];
            }
            curr[j] = min(taken, non_taken);
        }
        prev = curr;
    }

    int ans = prev[amount];
    if (ans >= 1e9)
    {
        return -1;
    }
    return ans;
}

int main()
{
    return 0;
}