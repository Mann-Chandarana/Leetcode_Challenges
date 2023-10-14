/*--------  Medium --------*/

/*- Longest Repeating Character Replacement -*/

//////// Question number 424.

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0, len = 0, largest_occ = INT_MIN;

    while (j < s.length())
    {
        mp[s[j]]++;
        largest_occ = max(largest_occ, mp[s[j]]);

        if (j - i + 1 - largest_occ > k)
        {
            mp[s[i]]--;
            i++;
        }

        len = max(len, j - i + 1);
        j++;
    }
    return len;
}

int main()
{
    return 0;
}