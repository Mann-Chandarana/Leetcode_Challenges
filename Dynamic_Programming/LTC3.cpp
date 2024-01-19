/*--------  Hard --------*/

/*- Count Vowels Permutation -*/

//////// Question number 1220.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int mod = 1e9 + 7;
int a = 0, e = 1, i = 2, o = 3, u = 4;

/* Recursion + Memorization */

ll solve(int ch, int n, vector<vector<ll>> &dp)
{
    if (n == 0)
        return 1;

    if (dp[ch][n] != -1)
        return dp[ch][n];

    ll answer = 0;

    if (ch == a)
        answer = (solve(e, n - 1, dp) % mod);

    else if (ch == e)
        answer = ((solve(a, n - 1, dp) + solve(i, n - 1, dp)) % mod);

    else if (ch == i)
        answer = ((solve(a, n - 1, dp) + solve(e, n - 1, dp) + solve(o, n - 1, dp) + solve(u, n - 1, dp)) % mod);

    else if (ch == o)
        answer = ((solve(i, n - 1, dp) + solve(u, n - 1, dp)) % mod);

    else if (ch == u)
        answer = (solve(a, n - 1, dp) % mod);

    return dp[ch][n] = answer;
}

int countVowelPermutation(int n)
{
    vector<vector<ll>> dp(5, vector<ll>(n + 1, -1));

    long answer = 0;
    for (ll i = 0; i < 5; i++)
        answer = ((answer + solve(i, n - 1, dp)) % mod);

    return answer;
}

/* Itertion */

int countVowelPermutation(int n)
{
    vector<vector<ll>> dp(5, vector<ll>(n + 1, 0));

    for (int i = 0; i < 5; i++)
        dp[i][0] = 1;

    for (int len = 1; len <= n; len++)
    {
        dp[a][len] = (dp[e][len - 1] % mod);

        dp[e][len] = ((dp[a][len - 1] + dp[i][len - 1]) % mod);

        dp[i][len] = ((dp[a][len - 1] + dp[e][len - 1] + dp[o][len - 1] + dp[u][len - 1]) % mod);

        dp[o][len] = ((dp[i][len - 1] + dp[u][len - 1]) % mod);

        dp[u][len] = (dp[a][len - 1] % mod);
    }

    ll answer = 0;

    for (int i = 0; i <= 4; i++)
    {
        answer = ((answer + dp[i][n - 1]) % mod);
    }
    return answer;
}

int main()
{
    return 0;
}