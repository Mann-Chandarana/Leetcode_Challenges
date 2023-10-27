/*-------- Medium -----------*/

/*- Longest Palindromic Substring -*/

//////// Question number 5.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int dp[1001][1001];

bool solve(string &s, int i, int j)
{
    if (i >= j)
        return true;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = solve(s, i + 1, j - 1);

    return dp[i][j] = false;
}

string longestPalindrome(string s)
{
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    int maxLen = INT_MIN;
    int sp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (solve(s, i, j))
            {
                if (j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    sp = i;
                }
            }
        }
    }

    return s.substr(sp, maxLen);
}

int main()
{
    cout << longestPalindrome("cbbd") << endl;
    return 0;
}