/* 14. Longest Common Prefix */

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string ans = "";
    sort(strs.begin(), strs.end());

    int n = strs.size();

    string first = strs[0], last = strs[n - 1];

    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
        {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}

int main()
{
    return 0;
}