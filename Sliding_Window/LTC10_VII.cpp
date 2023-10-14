/*--------  Medium --------*/

/*- Number of Substrings Containing All Three Characters -*/

//////// Question number 1358.

#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    unordered_map<char, int> mp;

    int i = 0, j = 0, ans = 0;

    while (j < s.length())
    {
        mp[s[j]]++;
        while (mp['a'] >= 1 and mp['b'] >= 1 and mp['c'] >= 1 and i <= j)
        {
            mp[s[i]]--;
            ans += (s.length() - j);
            i++;
        }
        j++;
    }
    return ans;
}

int main()
{
    cout << numberOfSubstrings("abcabc") << endl;
    return 0;
}