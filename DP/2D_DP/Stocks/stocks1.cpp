#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int n;
vector<vector<int>> dp(n, vector<int>(2, -1));

int f(int index, int buy, vector<int> &values, int n)
{
    if (index == n)
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(-values[index] + f(index + 1, 0, values, n),
                     0 + f(index + 1, 1, values, n));
    }
    else
    {
        profit = max(values[index] + f(index + 1, 1, values, n),
                     0 + f(index + 1, 0, values, n));
    }
    return dp[index][buy] = profit;
}

/* Tabulation */

int f(int buy, vector<int> &values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;

    int profit = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        dp[n][1] = max(-values[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
        dp[n][0] = max(values[index] + dp[index + 1][1], dp[index + 1][0]);
    }
    return dp[0][1];
}

/* Space Optimization */

int f(int buy, vector<int> &values, int n)
{
    vector<int> ahead(2, 0), curr(2, 0);

    ahead[0] = ahead[1] = 0;

    int profit = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        curr[1] = max(-values[index] + ahead[0], 0 + ahead[1]);
        curr[0] = max(values[index] + ahead[1], ahead[0]);

        ahead = curr;
    }
    return ahead[1];
}

/* Space optimization using variables */

int f(int buy, vector<int> &values, int n)
{
    int aheadNotbuy, aheadbuy, currNotbuy, currbuy;

    aheadNotbuy = aheadbuy = 0;

    int profit = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        currbuy = max(-values[index] + aheadNotbuy, 0 + aheadbuy);
        currNotbuy = max(values[index] + aheadbuy, aheadNotbuy);

        aheadbuy = currbuy;
        aheadNotbuy = currNotbuy;
    }
    return aheadbuy;
}

int main()
{
    return 0;
}