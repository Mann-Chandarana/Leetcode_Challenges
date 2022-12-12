/*- Climbing stairs -*/

//////// Question number  70.

#include <bits/stdc++.h>
using namespace std;

/** Using recurrsion **/

int climbStairs(int n)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }
    int first_type = climbStairs(n - 1);
    int second_type = climbStairs(n - 2);

    return first_type + second_type;
}

// ---------- Dynamic programming approach -------------

/** Using tabulation **/
int climbStairs(int n)
{
    int prev = 1, prev2 = 0, curr;
    for (int i = 1; i <= n; i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

/**  Using memorization **/
int count(int idx, vector<int> &dp)
{
    if (idx < 0)
    {
        return 0;
    }

    if (idx == 0)
    {
        return 1;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    dp[idx] = count(idx - 1, dp) + count(idx - 2, dp);

    return dp[idx];
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return count(n, dp);
}

int main()
{
    cout << climbStairs(2) << endl;
    return 0;
}