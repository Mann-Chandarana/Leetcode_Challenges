/*-------- Hard -----------*/

/*- Palindrome Partitioning II -*/

//////// Question number 132.

#include <bits/stdc++.h>
using namespace std;

/* Using recursion */

bool isPalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
        {
            return false;
        }
    }
    return true;
}

int solve(int i, string s, int n, vector<int> dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int mini = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            int cost = 1 + solve(j + 1, s, n, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}

int minCut(string s)
{
    int n = s.length();
    vector<int> dp(n, -1);
    return solve(0, s, n, dp) - 1;
}

/* Using Tabulation */

int minCut(string s)
{
    int n = s.length();

    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + dp[j + 1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }

    return dp[0] - 1;
}

/* Using Tabulation */

int minCut(string s)
{
    int sLen = s.length();
    bool pal[sLen][sLen];
    memset(pal, 0, sizeof(bool) * sLen * sLen);
    int minCuts[sLen];
    for (int i = sLen - 1; i >= 0; --i)
    {
        minCuts[i] = INT_MAX;
        for (int j = i; j < sLen; ++j)
        {
            if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]))
            {
                pal[i][j] = 1;
                if (j == sLen - 1)
                    minCuts[i] = 0;
                else
                    minCuts[i] = min(minCuts[i], minCuts[j + 1] + 1);
            }
        }
    }
    return minCuts[0];
}

int main()
{
    cout << minCut("bababcbadcede") << endl;
    return 0;
}