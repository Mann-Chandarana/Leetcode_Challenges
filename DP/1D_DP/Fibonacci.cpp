#include <bits/stdc++.h>
using namespace std;

/* Using recursion */

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* Using Memorization */

int n;
vector<int> dp(n + 1, -1);

int fibonaccii(int n)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonaccii(n - 1) + fibonacci(n - 2);
}

/* Using Tabulation */

int fibonacciii(int n)
{
    dp[0] = 0, dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

/* Using memorization */

int fibonacciiii(int n)
{
    int prev2 = 0, prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    return 0;
}