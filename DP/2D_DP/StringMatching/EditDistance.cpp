#include <bits/stdc++.h>
using namespace std;

/* Recursion and memorization */

int n, m;
vector<vector<int>> dp(n, vector<int>(m, -1));

int f(int i, int j, string &s1, string &s2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 0 + f(i - 1, j - 1, s1, s2);
    return dp[i][j] = 1 + min(f(i - 1, j, s1, s2), min(f(i, j - 1, s1, s2), f(i - 1, j - 1, s1, s2)));
                              /* Insert , Delete , Replace */  
}

/* One Base indexing */

int n, m;
vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

int f(int i, int j, string &s1, string &s2)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 0 + f(i - 1, j - 1, s1, s2);
    return dp[i][j] = 1 + min(f(i - 1, j, s1, s2), min(f(i, j - 1, s1, s2), f(i - 1, j - 1, s1, s2)));
}

/* Tabulation */

int f(int i, int j, string &s1, string &s2)
{
    int n, m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];
            dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }

    return dp[n][m];
}

/* Space Optimization */

int f(int i, int j, string &s1, string &s2)
{
    int n, m;
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 0 + prev[j - 1];
            curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
        }
        prev = curr;
    }

    return dp[n][m];
}

int main()
{
    return 0;
}