/*-------- Medium -----------*/

/*- Best Time to Buy and Sell Stock II -*/

//////// Question number 122.


#include <bits/stdc++.h>
using namespace std;

/* Using memorization */

int solve(vector<int> prices, bool buy, int index, vector<vector<int>> dp)
{
    if (index >= prices.size())
    {
        return 0;
    }

    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }

    if (buy)
    {
        return dp[index][buy] = max(-prices[index] + solve(prices, !buy, index + 1, dp), solve(prices, buy, index + 1, dp));
    }
    return dp[index][buy] = max(prices[index] + solve(prices, !buy, index + 1, dp), solve(prices, buy, index + 1, dp));
}

int maxProfit(vector<int> &prices)
{
    bool buy = true;
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return solve(prices, buy, 0, dp);
}

/* Using tabulation */

int maxProfit(vector<int> &prices)
{
    bool buy = true;
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    int n = prices.size();

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
    }

    return dp[0][1];
}

/* Using Space optimization */

int maxProfit(vector<int> &prices)
{
    bool buy = true;
    vector<int> front(2, 0), curr(2, 0);
    int n = prices.size();

    for (int i = n - 1; i >= 0; i--)
    {
        curr[1] = max(-prices[i] + front[0], front[1]);
        curr[0] = max(prices[i] + front[1], front[0]);
        front = curr;
    }

    return front[1];
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}