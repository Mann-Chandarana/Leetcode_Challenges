/*-------- Medium -----------*/

/*- Best Time to Buy and Sell Stock III -*/

//////// Question number 123.

#include <bits/stdc++.h>
using namespace std;

/* Using memorization */

int solve(vector<int> prices, int index, int transaction, int buy, vector<vector<vector<int>>> dp)
{
    if (index >= prices.size() || transaction == 0)
    {
        return 0;
    }

    if (dp[index][buy][transaction] != -1)
    {
        return dp[index][buy][transaction];
    }

    if (buy)
    {
        return dp[index][buy][transaction] = max(-prices[index] + solve(prices, index + 1, transaction, 0, dp), solve(prices, index + 1, transaction, 1, dp));
    }
    return dp[index][buy][transaction] = max(prices[index] + solve(prices, index + 1, transaction - 1, 1, dp), solve(prices, index + 1, transaction, 0, dp));
}

int maxProfit(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(prices, 0, 2, 1, dp);
}

/* Using tabulation */

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int trans = 1; trans < 3; trans++)
            {
                if (buy == 0)
                {
                    dp[i][buy][trans] = max(-prices[i] + dp[i + 1][1][trans], dp[i + 1][0][trans]);
                }
                else
                {
                    dp[i][buy][trans] = max(prices[i] + dp[i + 1][0][trans - 1], dp[i + 1][1][trans]);
                }
            }
        }
    }

    return dp[0][0][2];
}

/* Using Space optimization */

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0)), front(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int trans = 1; trans < 3; trans++)
            {
                if (buy == 0)
                {
                    curr[buy][trans] = max(-prices[i] + front[1][trans], front[0][trans]);
                }
                else
                {
                    curr[buy][trans] = max(prices[i] + front[0][trans - 1], front[1][trans]);
                }
            }
        }
        front = curr;
    }

    return front[1][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}