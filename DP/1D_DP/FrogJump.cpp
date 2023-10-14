#include <bits/stdc++.h>
using namespace std;

/* Using Recursion */

int f(int ind, vector<int> &heights)
{
    if (ind == 0)
        return 0;

    int one_steps = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int two_steps = INT_MAX;
    if (ind > 1)
        two_steps = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return min(one_steps, two_steps);
}

/* Using Memorization */

int n;
vector<int> dp(n + 1, -1);

int fi(int ind, vector<int> &heights)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int one_steps = fi(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int two_steps = INT_MAX;
    if (ind > 1)
        two_steps = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(one_steps, two_steps);
}

/* Using Tabulation */

int fii(int n, vector<int> &heights)
{
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int first_steps = dp[i - 1] + abs(heights[i] - heights[i - 1]);

        int two_steps = INT_MAX;

        if (i > 1)
            two_steps = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(first_steps, two_steps);
    }
    return dp[n];
}

/* Using space optimization */

int fii(int n, vector<int> &heights)
{
    int prev = 0, prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int first_steps = prev + abs(heights[i] - heights[i - 1]);

        int two_steps = INT_MAX;

        if (i > 1)
            two_steps = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(first_steps, two_steps);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    return 0;
}