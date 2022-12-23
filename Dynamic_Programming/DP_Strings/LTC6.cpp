/*-------- Medium -----------*/

/*- Delete Operation for Two Strings  -*/

//////// Question number 583.

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

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    int ans = longestCommonSubsequence(word1,word2);
    int del = n - ans;
    int insert = m - ans;
    return del+insert;
}

int main()
{
    cout << minDistance("sea", "eat") << endl;
    return 0;
}