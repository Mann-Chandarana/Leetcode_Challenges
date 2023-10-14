//////// Question number 121.

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), mini = INT_MAX, profit=0, max_profit=0;

    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(prices[i], mini);
        profit = prices[i] - mini;
        max_profit = max(max_profit, profit);
    }
    return max_profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;

    return 0;
}