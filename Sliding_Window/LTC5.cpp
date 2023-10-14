/*--------  Medium --------*/

/*- Longest Substring Without Repeating Characters -*/

//////// Question number 3.

#include <bits/stdc++.h>
using namespace std;

/* Using Sets  */

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> t;
    int m = 0;
    int l = 0, r = 0;
    while (r < s.size())
    {
        while (t.find(s[r]) != t.end())
        {
            t.erase(s[l]);
            l++;
        }
        t.insert(s[r]);
        m = max(m, r - l + 1);
        r++;
    }
    return m;
}

/* Using maps */

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;

    int i = 0, j = 0, len = 0;

    while (j < s.length())
    {
        mp[s[j]]++;
        if (j - i + 1 == mp.size())
            len = max(len, j - i + 1);

        else if (j - i + 1 > mp.size())
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                mp.erase(s[i]);

            i++;
        }
        j++;
    }
    return len;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}