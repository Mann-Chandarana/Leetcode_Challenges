#include <bits/stdc++.h>
using namespace std;

/* Recursion and memorization */

int n, m;
vector<vector<int>> dp(n, vector<int>(m, -1));

int f(int i, int j, string &pattern, string &text)
{
    if (i < 0 and j < 0)
        return true;
    if (i < 0 and j >= 0)
        return false;
    if (j < 0 and i >= 0)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] != '*')
                return false;
        }
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (pattern[i] == text[j] || pattern[i] == '?')
        return dp[i][j] = f(i - 1, j - 1, pattern, text);

    if (pattern[i] == '*')
        return dp[i][j] = (f(i - 1, j, pattern, text) || f(i, j - 1, pattern, text));

    return dp[i][j] = false;
}

/* 1 Based indexing */

int n, m;
vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

int f(int i, int j, string &pattern, string &text)
{
    if (i == 0 and j == 0)
        return true;
    if (i == 0 and j > 0)
        return false;
    if (j == 0 and i > 0)
    {
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
                return false;
        }
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
        return dp[i][j] = f(i - 1, j - 1, pattern, text);

    if (pattern[i - 1] == '*')
        return dp[i][j] = (f(i - 1, j, pattern, text) || f(i, j - 1, pattern, text));

    return dp[i][j] = false;
}

/* Tabulation */

int n, m;
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

int f(int i, int j, string &pattern, string &text)
{
    dp[0][0] = true;

    for (int j = 1; j <= m; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++)
    {
        int flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else if (pattern[i - 1] == '*')
                return dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);

            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

/* Space Optimization */

int n, m;
vector<int> previ(m + 1, 0), curr(m + 1, 0);

int f(int i, int j, string &pattern, string &text)
{
    previ[0] = true;

    for (int j = 1; j <= m; j++)
        previ[j] = false;

    for (int i = 1; i <= n; i++)
    {
        int flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag;
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                curr[j] = previ[j - 1];

            else if (pattern[i - 1] == '*')
                return curr[j] = (previ[j] || curr[j - 1]);

            else
                curr[j] = false;
        }
        previ = curr;
    }

    return previ[m];
}

int main()
{
    return 0;
}