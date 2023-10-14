/** Longest Common substring :- Geeks for geeks **/

// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-common-substring1452

#include <bits/stdc++.h>
using namespace std;

/** Using Recursion **/

int solver(string s1, string s2, int i, int j, int count)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        count = solver(s1, s2, i - 1, j - 1, count + 1);
    }

    return max(count, max(solver(s1, s2, i - 1, j, 0), solver(s1, s2, i, j - 1, 0)));
}

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    return solver(S1, S2, n - 1, m - 1,0);
}

/** Using Tabulation **/

int Solver(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans,dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    return Solver(S1,S2);
}


int main()
{
    cout << longestCommonSubstr("ABC", "ACB", 3, 3) << endl;
    return 0;
}