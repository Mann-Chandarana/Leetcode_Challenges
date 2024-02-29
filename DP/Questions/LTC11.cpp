/*-------- Hard --------*/

/*- K Inverse Pairs Array -*/

//////// Question number 629.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

typedef vector<pair<int, int>> vpii;
typedef vector<pair<pair<int, int>, int>> vppi;
typedef unordered_map<string, vector<string>> umps;

/**** Recursion + Memorization *****/

int mod = 1e9 + 7;

int fn(int n, int k, vector<vector<int>> &dp)
{
    if (n == 0)
        return 0;

    if (k == 0)
        return 1;

    if (dp[n][k] != -1)
        return dp[n][k];

    int result = 0;

    for (int inv = 0; inv <= min(k, n - 1); inv++)
        result = (result % mod + fn(n - 1, k - inv, dp) % mod) % mod;

    return dp[n][k] = result % mod;
}

int kInversePairs(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return fn(n, k, dp);
}

/**** Tabulation *****/

int kInversePairs(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int result = 0;

            for (int inv = 0; inv <= min(j, i - 1); inv++)
                result = (result % mod + dp[i - 1][j - inv] % mod) % mod;

            dp[i][j] = result;
        }
    }
    return dp[n][k];
}

int main()
{
    return 0;
}