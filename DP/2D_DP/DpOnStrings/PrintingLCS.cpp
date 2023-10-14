#include <bits/stdc++.h>
using namespace std;

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

    // Time Complexity of printing is O(N+M)
    int len = dp[n][m];

    string ans = "";
    for (int i = 0; i < len; i++)
        ans[i] = '#';

    int index = len - 1;
    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (s[i - 1] == s[j - 1])
        {
            ans[index] = s[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << ans << endl;
}

int main()
{
    return 0;
}