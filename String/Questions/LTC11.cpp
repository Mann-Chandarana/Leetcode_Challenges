/* 844. Backspace String Compare */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define vpii vector<pair<int, int>>
#define vppi vector<pair<pair<int, int>, int>>
#define umps unordered_map<string, vector<string>>

bool backspaceCompare(string s, string t)
{
    int n = s.length(), m = t.length();

    int hash = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '#')
            hash++;
        else if (hash > 0)
            hash--, s[i] = '#';
    }
    hash = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        if (t[i] == '#')
            hash++;
        else if (hash > 0)
            hash--, t[i] = '#';
    }

    int i = 0, j = 0;

    while (i < n and j < m)
    {
        if (s[i] != '#' and t[j] != '#')
        {
            if (s[i] != t[j])
                return false;
            i++, j++;
            continue;
        }
        if (s[i] == '#')
            i++;
        if (t[j] == '#')
            j++;
    }
    return true;
}

int main()
{
    return 0;
}