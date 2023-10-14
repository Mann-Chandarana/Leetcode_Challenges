/* GFG :- Longest K unique characters substring */

/*
https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-k-unique-characters-substring
*/

#include <bits/stdc++.h>
using namespace std;

/* With while loop */

int longestKSubstr(string s, int k)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0, ans = INT_MIN;

    while (j < s.length())
    {
        mp[s[j]]++;

        if (mp.size() == k)
            ans = max(ans, j - i + 1);

        if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }

        j++;
    }

    return ans == INT_MIN ? -1 : ans;
}

/* Without while loop */

int longestKSubstr(string s, int k)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0, ans = INT_MIN;

    while (j < s.length())
    {
        mp[s[j]]++;

        if (mp.size() == k)
            ans = max(ans, j - i + 1);

        if (mp.size() > k)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                mp.erase(s[i]);
            i++;
        }

        j++;
    }
}

int main()
{
    cout << longestKSubstr("aaaa", 2) << endl;
    return 0;
}