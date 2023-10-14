/*- Best Time to Buy and Sell Stock -*/

//////// Question number 121.

/* See this solution for the answer */

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/39038/kadane-s-algorithm-since-no-one-has-mentioned-about-this-so-far-in-case-if-interviewer-twists-the-input/?orderBy=most_votes

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0, max_profit = INT_MIN, mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prices[i]);
        profit = prices[i] - profit;
        max_profit = max(profit, max_profit);
    }
    return max_profit;
}

int main()
{
    return 0;
}