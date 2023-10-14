#include <bits/stdc++.h>
using namespace std;

/* Using Tabulation */

int n;
vector<int> dp(n + 1, -1);

int climbingStairs(int n)
{
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/* Using Space optimization */

int climbingStairss(int n)
{
    int prev2 = 1, prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
    }

    return prev;
}

int main()
{
    return 0;
}