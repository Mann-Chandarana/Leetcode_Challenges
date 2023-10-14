/*-------- Medium -----------*/

/*- Domino and Tromino Tiling -*/

//////// Question number 790.

#include <bits/stdc++.h>
using namespace std;

/** When only Domino is given at that time 
--> Recurrence relation is :- f(n) = f(n-1)+f(n-2).
**/

/** Using hit and trail appraoch 
1) when n = 1 means 2x1 board so total possiblities are 1
2) when n = 2 means 2x2 board so total possiblities are 2
1) when n = 3 means 2x3 board so total possiblities are 5
1) when n = 4 means 2x4 board so total possiblities are 11
**/

int mod = (1e9 + 7);

int solve(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    if (n == 3)
        return 5;

    if (n == 4)
        return 11;

    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    dp[4] = 11;

    for (int i = 5; i <= n; i++)
    {
        dp[i] = (2 * (dp[i - 1] % mod) + (dp[i - 3] % mod)) % mod;
    }

    return dp[n];
}

int numTilings(int n)
{
    return solve(n);
}

int main()
{
    cout << numTilings(6) << endl;
    return 0;
}