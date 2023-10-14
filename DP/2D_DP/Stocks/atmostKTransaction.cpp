#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int k, n;
vector<vector<int>> dp1(n, vector<int>(2 * k, -1));

int f(int ind, int trans, int n, vector<int> &values)
{
    if (ind == n || trans == 2 * k)
        return 0;

    if (dp1[ind][trans] != -1)
        return dp1[ind][trans];

    int profit = 0;

    if (trans % 2 == 0) // buy
    {
        profit = max(-values[ind] + f(ind + 1, trans + 1, n, values),
                     0 + f(ind + 1, trans, n, values));
    }
    else // sell
    {
        profit = max(values[ind] + f(ind + 1, trans + 1, n, values),
                     0 + f(ind + 1, trans, n, values));
    }

    return dp1[ind][trans] = profit;
}

/* Tabulation */

int f(int k, int trans, int n, vector<int> &values)
{
    vector<vector<int>> dp2(n, vector<int>(2 * k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int trans = 2 * k - 1; trans >= 0; trans--)
        {
            int profit = 0;

            if (trans % 2 == 0) // buy
            {
                profit = max(-values[ind] + dp2[ind + 1][trans + 1],
                             0 + dp2[ind + 1][trans]);
            }
            else // sell
            {
                profit = max(values[ind] + dp2[ind + 1][trans + 1],
                             0 + dp2[ind + 1][trans]);
            }
            dp2[ind][trans] = profit;
        }
    }
    dp2[0][0];
}

/* Space Optimization */

int f(int k, int trans, int n, vector<int> &values)
{
    vector<int> ahead(2 * k + 1, 0), curr(2 * k + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int trans = 2 * k - 1; trans >= 0; trans--)
        {
            int profit = 0;

            if (trans % 2 == 0) // buy
            {
                profit = max(-values[ind] + ahead[trans + 1],
                             0 + ahead[trans]);
            }
            else // sell
            {
                profit = max(values[ind] + ahead[trans + 1],
                             0 + ahead[trans]);
            }
            curr[trans] = profit;
        }
        ahead = curr;
    }
    ahead[0];
}

int main()
{
    return 0;
}