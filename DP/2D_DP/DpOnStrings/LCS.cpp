#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int n, m;
vector<vector<int>> dp(n, vector<int>(m, -1));

int f(int i, int j, string &s, string &t)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = 1 + f(i - 1, j - 1, s, t);

    return dp[i][j] = max(f(i - 1, j, s, t), f(i, j - 1, s, t));
}

/* Tabulation */

int f(int n, int m, string &s, string &t)
{
    // Shifting of index takes place so -1 --> 0 and 0--> 1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

/* Space Optimization */

int f(int n, int m, string &s, string &t)
{
    // Shifting of index takes place so -1 --> 0 and 0--> 1
    vector<int> prev(m + 1, -1), curr(m + 1, -1);

    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];

            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    return 0;
}