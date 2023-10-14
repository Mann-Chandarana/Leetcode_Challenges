#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/****** Approach -1) *******/

bool isSubsequence(string s, string t)
{
    int i = s.length() - 1, j = t.length() - 1;

    while (i >= 0 and j >= 0)
    {
        if (s[i] == t[j])
            i--, j--;
        else
            j--;
    }
    if (i <0)
        return true;
    return false;
}

/****** Approach -2) Using Dynamic Programming *******/

/* Recurison + Memorization */

bool solve(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i < 0)
        return true;

    if (j < 0)
        return false;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        dp[i][j] = solve(i - 1, j - 1, s, t, dp);
    else
        dp[i][j] = solve(i, j - 1, s, t, dp);

    return dp[i][j];
}

bool isSubsequence(string s, string t)
{
    int n = s.length(), m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return solve(n - 1, m - 1, s, t, dp);
}

/****** Approach -2) *******/

bool isSubsequence(string s, string t)
{
    map<char, vector<int>> mp;

    for (int i = 0; i < t.length(); i++)
        mp[t[i]].push_back(i);

    int prev = -1;

    for (int i = 0; i < s.length(); i++)
    {
        if (mp.find(s[i]) == mp.end())
            return false;

        auto it = upper_bound(all(mp[i]), prev);

        if (it == mp[i].end())
            return false;

        prev = *it;
    }
    return true;
}

int main()
{
    return 0;
}