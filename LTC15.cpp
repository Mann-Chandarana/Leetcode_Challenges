/* 389. Find the Difference */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach -1) */

char findTheDifference(string s, string t)
{
    vector<int> mp(26, 0);

    int n = s.length(), m = t.length();

    for (int i = 0; i < n; i++)
        mp[s[i] - 'a']++;

    for (int i = 0; i < m; i++)
    {
        if (mp[t[i] - 'a'] == 0)
            return t[i];
        else
            mp[t[i] - 'a']--;
    }
    return ' ';
}

/* Approach -2) */

char findTheDifference(string s, string t)
{
    int sum = 0, n = s.length(), m = t.length();

    for (int i = 0; i < m; i++)
        sum += int(t[i]);

    cout << sum << endl;

    for (int i = 0; i < n; i++)
        sum -= int(s[i]);

    return sum;
}

/* Approach -3) */

char findTheDifference(string s, string t)
{
    int xori = 0, n = s.length(), m = t.length();

    for (int i = 0; i < n; i++)
        xori ^= s[i];

    for (int i = 0; i < m; i++)
        xori ^= t[i];

    return xori;
}

int main()
{
    return 0;
}