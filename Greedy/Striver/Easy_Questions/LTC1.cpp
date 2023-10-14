/* 455. Assign Cookies */

#include <bits/stdc++.h>
using namespace std;

/* Using lower bound */

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int res = 0;

    for (int i = 0; i < g.size(); i++)
    {
        auto value = lower_bound(s.begin(), s.end(), g[i]);
        if (value != s.end())
            res++, s.erase(value);
    }
    return res;
}

/* Using sorting function */

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0, res = 0;

    while (i < g.size() and j < s.size())
    {
        if (s[j] >= g[i])
            res++, i++, j++;
        else
            j++;
    }
    return res;
}

int main()
{
    return 0;
}