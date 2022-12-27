/*-------- Medium -----------*/

/*- Longest String Chain -*/

//////// Question number 1048.

#include <bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2)
{
    if (s1.size() != s2.size() + 1)
    {
        return false;
    }

    int first = 0, second = 0;

    while (first < s1.size())
    {
        if (second < s2.size() and s1[first] == s2[second])
        {
            first++, second++;
        }
        else
        {
            first++;
        }
    }

    if (first == s1.size() and second == s2.size())
    {
        return true;
    }
    return false;
}

bool cmp(string s1, string s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = INT_MIN;
    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (compare(arr[i], arr[prev]) and 1 + dp[prev] > dp[i])
            {
                dp[i] = dp[prev] + 1;
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

int main()
{
    return 0;
}