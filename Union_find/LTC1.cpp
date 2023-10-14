#include <bits/stdc++.h>
using namespace std;

/* Using sets and DSU */

int par[26];

int find(int x)
{
    if (par[x] == -1)
        return x;
    return par[x] = find(par[x]);
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x != y)
        par[max(x, y)] = min(x, y);
}

string smallestEquivalentString(string s1, string s2, string baseStr)
{

    memset(par, -1, sizeof(par));

    for (auto i = 0; i < s1.size(); ++i)
        Union(s1[i] - 'a', s2[i] - 'a');

    for (auto i = 0; i < baseStr.size(); i++)
        baseStr[i] = find(baseStr[i] - 'a') + 'a';

    return baseStr;
}

/* Simple solution */

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    vector<char> ch(26);

    for (int i = 0; i < 26; i++)
    {
        ch[i] = 'a' + i;
    }

    for (int i = 0; i < s1.size(); i++)
    {
        char to_replace = max(ch[s1[i] - 'a'], ch[s2[i] - 'a']);
        char replace_with = min(ch[s1[i] - 'a'], ch[s2[i] - 'a']);

        for (int i = 0; i < 26; i++)
            if (ch[i] == to_replace)
                ch[i] = replace_with;
    }

    for (int i = 0; i < baseStr.length(); i++)
    {
        baseStr[i] = ch[baseStr[i] - 'a'];
    }

    return baseStr;
}

int main()
{
    cout << smallestEquivalentString("leetcode", "programs", "sourcecode") << endl;
    return 0;
}