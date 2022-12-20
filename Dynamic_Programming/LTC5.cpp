/*- Fibonacci in GFG -*/

// https://practice.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp

#include <bits/stdc++.h>
using namespace std;

long long int m = 1e9 + 7;
long long int dp[100001];

/***** recursion *****/

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/***** topDown approach - memorization *****/

long long int solve(int n)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n] % m;
    }

    return dp[n] = (solve(n - 1) + solve(n - 2)) % m;
}

long long int topDown(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(n);
}

/***** bottomUp approach - tabulation *****/

long long int bottomUp(int n)
{
    vector<int> dp(n + 1, -1);
    dp[1] = 1;
    dp[0] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % m;
    }

    return dp[n] % m;
}

/***** bottomUp approach - Space optimization *****/

long long int bottomUp(int n)
{
    int prev2 = 0, prev = 1, curr;

    for (int i = 2; i <= n; i++)
    {
        curr = (prev + prev2) % m;
        prev2 = prev;
        prev = curr;
    }

    return prev % m;
}

int main()
{
    return 0;
}