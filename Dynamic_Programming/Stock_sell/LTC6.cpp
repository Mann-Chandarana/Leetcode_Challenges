/*-------- Medium -----------*/

/*- Best Time to Buy and Sell Stock with Cooldown -*/

//////// Question number 309.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> prices, int idx, bool buy, vector<vector<int>> &dp)
{
    if (idx >= prices.size())
    {
        return 0;
    }

    if (dp[idx][buy] != -1)
    {
        return dp[idx][buy];
    }

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[idx] + solve(prices, idx + 1, 0, dp), 0 + solve(prices, idx + 1, 1, dp));
    }
    else
    {
        profit = max(prices[idx] + solve(prices, idx + 2, 1, dp), 0 + solve(prices, idx + 1, 0, dp));
    }
    return dp[idx][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 2, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> front(2, 0), curr(2, 0), front2(2, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        curr[1] = max(-prices[idx] + front[0], 0 + front[1]);
        curr[0] = max(prices[idx] + front2[1], 0 + front[0]);
        front2 = front;
        front = curr;

    }
    return curr[1];
}

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}