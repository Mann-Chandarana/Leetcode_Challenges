#include <bits/stdc++.h>
using namespace std;

/* Tabulation */

int f(int n, int m, string &s, string &t)
{
    // Shifting of index takes place so -1 --> 0 and 0--> 1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }

            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

/* Space Optimization */

int f(int n, int m, string &s, string &t)
{
    // Shifting of index takes place so -1 --> 0 and 0--> 1
    vector<int> prev(m + 1, -1), curr(m + 1, -1);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                ans = max(curr[j], ans);
            }

            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}

int main()
{
    return 0;
}