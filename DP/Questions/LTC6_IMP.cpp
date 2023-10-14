/*--------  Medium --------*/

/*- Extra Characters in a String -*/

//////// Question number 2707.

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

/******* Recursion + Memorization *******/

unordered_set<string> st;
int n;

int solve(int idx, string s, vector<string> &dictionary, vector<int> &dp)
{
    if (idx >= n)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    string currStr = "";
    int minExtra = INT_MAX;

    for (int i = idx; i < n; i++)
    {
        currStr += s[i];

        int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;

        int nextExtra = solve(i + 1, s, dictionary, dp);

        minExtra = min(minExtra, currExtra + nextExtra);
    }
    return dp[idx] = minExtra;
}

int minExtraChar(string s, vector<string> &dictionary)
{
    for (auto &element : dictionary)
        st.insert(element);

    n = s.length();

    vector<int> dp(n + 1, -1);
    return solve(0, s, dictionary, dp);
}

/******* Tabulation *******/

int minExtraChar(string s, vector<string> &dictionary)
{
    n = s.length();

    vector<int> dp(n+1, 0);

    for (auto &element : dictionary)
        st.insert(element);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        string currStr = "";
        int minExtra = INT_MAX;

        for (int i = idx; i < n; i++)
        {
            currStr.push_back(s[i]);

            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;

            int nextExtra = dp[i + 1];

            minExtra = min(minExtra, currExtra + nextExtra);
        }

        dp[idx] = minExtra;
    }

    return dp[0];
}

int main()
{
    return 0;
}