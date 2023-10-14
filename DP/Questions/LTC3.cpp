/*--------  Medium --------*/

/*- Interleaving String -*/

//////// Question number 97.

#include <bits/stdc++.h>
using namespace std;

/*************** Using Recursion + Memorization ****************/

// 1) Using 3-DP

bool solve(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp)
{
    if (k >= s3.length())
    {
        if (i >= s1.length() and j >= s2.length())
            return true;
        else
            return false;
    }

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    bool answer1 = false, answer2 = false;

    if (s1[i] == s3[k])
        answer1 = solve(i + 1, j, k + 1, s1, s2, s3, dp);

    if (s2[j] == s3[k])
        answer2 = solve(i, j + 1, k + 1, s1, s2, s3, dp);

    return dp[i][j][k] = answer1 || answer2;
}

bool isInterleave(string s1, string s2, string s3)
{
    vector<vector<vector<int>>> dp(s1.length() + 1, vector<vector<int>>(s2.length() + 1, vector<int>(s3.length() + 1, -1)));
    return solve(0, 0, 0, s1, s2, s3, dp);
}

// Using 2-Dp

bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp)
{
    if (i + j >= s3.length())
    {
        if (i >= s1.length() and j >= s2.length())
            return true;
        else
            return false;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    bool answer1 = false, answer2 = false;

    if (s1[i] == s3[i + j])
        answer1 = solve(i + 1, j, s1, s2, s3, dp);

    if (s2[j] == s3[i + j])
        answer2 = solve(i, j + 1, s1, s2, s3, dp);

    return dp[i][j] = answer1 || answer2;
}

bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(0, 0, s1, s2, s3, dp);
}

/*************** Using Tabulation ****************/

bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i + j >= s3.length())
            {
                if (i >= s1.length() and j >= s2.length())
                    dp[i][j] = 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            bool answer1 = false, answer2 = false;

            if (s1[i] == s3[i + j])
                answer1 = dp[i + 1][j];

            if (s2[j] == s3[i + j])
                answer2 = dp[i][j + 1];

            dp[i][j] = answer1 || answer2;
        }
    }

    return dp[0][0];
}

int main()
{
    cout << isInterleave("aabcc", "dbbca", "aadbbcbcac");

    // aa ab aaba
    return 0;
}