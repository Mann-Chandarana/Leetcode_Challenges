/*-------- Hard -----------*/

/*- Shortest common supersequence  -*/

//////// Question number 1092.

#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string ans = "";
    int len = dp[n][m];
    int index = len - 1;
    while (i > 0 and j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            ans += text1[i - 1];
            index--;
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] >= dp[i - 1][j])
            {
                ans += text2[j - 1];
                j--;
            }
            else
            {
                ans += text1[i - 1];
                i--;
            }
        }
    }

    while (i > 0)
    {
        ans += text1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += text2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    cout << shortestCommonSupersequence("abac", "cab") << endl;
    return 0;
}