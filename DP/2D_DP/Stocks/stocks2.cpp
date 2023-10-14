#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int n;
vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

int f(int ind, int buy, int cap, int n, vector<int> &values)
{
    if (cap == 0)
        return 0;

    if (ind == n)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit = 0;

    if (buy)
    {
        profit = max(-values[ind] + f(ind + 1, 0, cap, n, values),
                     0 + f(ind + 1, 1, cap, n, values));
    }
    else
    {
        profit = max(values[ind] + f(ind + 1, 1, cap - 1, n, values),
                     0 + f(ind + 1, 0, cap, n, values));
    }

    return dp[ind][buy][cap] = profit;
}

/* Recursion + Memorization -- Using 2D array */

vector<vector<int>> dp1(n, vector<int>(4, -1));

int f(int ind, int trans, int n, vector<int> &values)
{
    if (ind == n || trans == 4)
        return 0;

    if (dp1[ind][trans] != -1)
        return dp1[ind][trans];

    int profit = 0;

    if (trans % 2 == 0) // buy
    {
        profit = max(-values[ind] + f(ind + 1, trans + 1, n, values),
                     0 + f(ind + 1, trans, n, values));
    }
    else            // sell
    {
        profit = max(values[ind] + f(ind + 1, trans + 1, n, values),
                     0 + f(ind + 1, trans, n, values));
    }

    return dp1[ind][trans] = profit;
}

/* Tabulation */

int f(int n, vector<int> &values)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-values[ind] + dp[ind + 1][0][cap],
                                 0 + dp[ind + 1][1][cap]);
                }
                else
                {
                    profit = max(values[ind] + dp[ind + 1][1][cap - 1],
                                 0 + dp[ind + 1][0][cap]);
                }

                return dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}

/* Space Optimization */

int f(int n, vector<int> &values)
{
    vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-values[ind] + ahead[0][cap],
                                 0 + ahead[1][cap]);
                }
                else
                {
                    profit = max(values[ind] + ahead[1][cap - 1],
                                 0 + ahead[0][cap]);
                }

                return curr[buy][cap] = profit;
            }
        }
        ahead = curr;
    }
    return ahead[1][2];
}

int main()
{
    return 0;
}