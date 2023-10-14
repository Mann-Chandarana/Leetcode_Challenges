/*-------- Hard -----------*/

/*- Minimum Insertion Steps to Make a String Palindrome  -*/

//////// Question number 1312.

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int i = 0; i <= m; i++)
    {
        prev[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cur[0] = 0;
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                cur[j] = 1 + prev[j - 1];
            }
            else
            {
                cur[j] = max(prev[j], cur[j - 1]);
            }
        }
        prev = cur;
    }

    return prev[m];
}

int longestPalindromeSubseq(string s)
{
    string s1 = s;
    reverse(s.begin(), s.end());
    return longestCommonSubsequence(s1, s);
}

int minInsertions(string s)
{
    int value = longestPalindromeSubseq(s);
    return (s.length() - value);
}

int main()
{
    return 0;
}