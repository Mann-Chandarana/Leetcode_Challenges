/*-------- Medium -----------*/

/*- Coin Change II -*/

//////// Question number 518.

#include <bits/stdc++.h>
using namespace std;

/* Using Memorization */

int solve(vector<int> coins, int amount, int idx, vector<vector<int>> dp)
{
    if (idx == 0 || amount == 0)
    {
        return (amount % coins[0] == 0);
    }

    if (dp[idx][amount] != -1)
    {
        return dp[idx][amount];
    }

    int not_taken = 0 + solve(coins, amount, idx - 1, dp);

    int taken = 0;

    if (coins[idx] <= amount)
    {
        taken = solve(coins, amount - coins[idx], idx, dp);
    }

    return dp[idx][amount] = (taken + not_taken);
}

int change(int amount,vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int val = solve(coins, amount, n - 1, dp);

    return val;
}

/* Using Space optimization */

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            prev[i] = 1;
        }
        else
        {
            prev[i] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int non_taken = 0 + prev[j];

            int taken = 0;
            if (coins[i] <= j)
            {
                taken = curr[j - coins[i]];
            }
            curr[j] = taken + non_taken;
        }
        prev = curr;
    }

    return prev[amount];
}

int main()
{
    return 0;
}