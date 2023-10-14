#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    bool buy = true;
    vector<int> front(2, 0), curr(2, 0);
    int n = prices.size();

    for (int i = n - 1; i >= 0; i--)
    {
        curr[1] = max(-prices[i] + front[0], front[1]);
        curr[0] = max(prices[i] + front[1] - fee, front[0]);
        front = curr;
    }

    return front[1];
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << maxProfit(prices, 2) << endl;
    return 0;
}