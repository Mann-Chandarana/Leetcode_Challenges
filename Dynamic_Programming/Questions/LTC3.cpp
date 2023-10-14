/*-------- Hard -----------*/

/*- Wildcard matching -*/

//////// Question number 44.

#include <bits/stdc++.h>
using namespace std;

/** Using memorization and recursion **/

bool solve(string s, string p, int i, int j, vector<vector<int>> dp)
{
    if (i < 0 and j < 0)
    {
        return true;
    }

    if (i >= 0 and j < 0)
    {
        return false;
    }
    if (i < 0 and j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
    }
    else
    {
        if (p[j] == '*')
        {
            return dp[i][j] = (solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp));
        }
        else
        {
            return false;
        }
    }
}

bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(s, p, n - 1, m - 1, dp);
}

/** Using tabulation **/

bool isMatch(string s, string p)
{
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for (int j = 0; j < p.size() && p[j] == '*'; ++j)
    {
        dp[0][j + 1] = true;
    }

    for (int i = 1; i <= s.size(); ++i)
    {
        for (int j = 1; j <= p.size(); ++j)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
            }
        }
    }

    return dp[s.size()][p.size()];
}

/** Using Space optimization **/

bool isMatch(string s, string p)
{
     vector<bool>curr(p.size() + 1, false),prev(p.size()+1,false);

    prev[0] = true;
    for (int j = 0; j < p.size() && p[j] == '*'; ++j)
    {
        prev[j + 1] = true;
    }

    for (int i = 1; i <= s.size(); ++i)
    {
        for (int j = 1; j <= p.size(); ++j)
        {
            if (p[j - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1];
            }
            else
            {
                curr[j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && prev[j - 1];
            }
        }
        prev = curr;
    }

    return prev[p.size()];
}

int main()
{
    cout << isMatch("adceb", "*a*b") << endl;
    return 0;
}