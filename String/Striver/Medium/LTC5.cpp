/*-------- Medium -----------*/

/*- Sum of Beauty of All Substrings  -*/

//////// Question number 1718.

#include <bits/stdc++.h>
using namespace std;

/* Using Brute force approach */

int beautySum(string s)
{
    int n = s.length();
    int sum = 0;
    // First of all create all the substring

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mp;
        for (int j = i; j < n; j++)
        {
            mp[s[j]]++;
            int maxFreq = 0, minFreq = INT_MAX;

            for (auto it : mp)
            {
                maxFreq = max(maxFreq, it.second);
                minFreq = min(minFreq, it.second);
            }
            sum += (maxFreq - minFreq);
        }
    }
    return sum;
}

/* Using MultiSet approach */

int beautySum(string s)
{
    int n = s.length();
    int sum = 0;
    // First of all create all the substring

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mp;
        multiset<int> st;

        for (int j = i; j < n; j++)
        {
            if (mp.find(s[j]) != mp.end())
                st.erase(st.find(mp[s[j]]));

            mp[s[j]]++;
            st.insert(mp[s[j]]);

            sum += (*st.rbegin() - *st.begin());
        }
    }
    return sum;
}

int main()
{
    return 0;
}