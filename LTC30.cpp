#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int minSteps(string s, string t)
{
    vector<int> freq(26, 0);

    int n = s.length(), m = t.length(), count = 0;

    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    for (auto ch : t)
    {
        if (freq[ch - 'a'] > 0)
            freq[ch - 'a']--;
        else
            count++;
    }
    return count;
}

int main()
{
    return 0;
}