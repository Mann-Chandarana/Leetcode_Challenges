/*-------- Hard -----------*/

/*- Distinct Subsequences  -*/

//////// Question number 115.

#include <bits/stdc++.h>
using namespace std;

/** Using memorization **/

int solver(string s, string t, int i, int j, vector<vector<int>> dp)
{
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == t[j])
    {
        return dp[i][j] = (solver(s, t, i - 1, j - 1, dp) + solver(s, t, i - 1, j, dp));
    }
    return dp[i][j] = solver(s, t, i - 1, j, dp);
}

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solver(s, t, n - 1, m - 1, dp);
}

/** Using Space optimization **/

int numDistinct(string s, string t)
{
    long long n = s.length(), m = t.length();
    vector<long long> curr(m + 1, 0), prev(m + 1, 0);

    prev[0] = 1;

    for (int j = 1; j <= m; j++)
    {
        prev[j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        curr[0] = 1;
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = prev[j - 1] + prev[j];
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[m];
}

/** Using Space optimization -O(M) **/

int numDistinct(string s, string t)
{
    long long n = s.length(), m = t.length();
    vector<long long> curr(m + 1, 0);

    curr[0] = 1;

    for (int j = 1; j <= m; j++)
    {
        curr[j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        curr[0] = 1;
        for (int j = m; j >=0; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = curr[j - 1] + curr[j];
            }
            else
            {
                curr[j] = curr[j];
            }
        }
    }

    return curr[m];
}

int main()
{
    cout << numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}