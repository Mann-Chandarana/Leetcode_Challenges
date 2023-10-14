/*--------  Medium --------*/

/*- Permutation in String -*/

//////// Question number 567.

#include <bits/stdc++.h>
using namespace std;

/*----------- Best solution -----------*/

bool checkInclusion(string s1, string s2)
{
    vector<int> cur(26), goal(26);
    for (char c : s1)
        goal[c - 'a']++;
    for (int i = 0; i < s2.size(); i++)
    {
        cur[s2[i] - 'a']++;
        if (i >= s1.size())
            cur[s2[i - s1.size()] - 'a']--;
        if (goal == cur)
            return true;
    }
    return false;
}

/*----------- Average solution -----------*/

bool checkInclusion(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2)
        return false;

    vector<int> count1(26, 0), count2(26, 0);

    int i;
    for (i = 0; i < n1; i++)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    if (count1 == count2)
        return true;

    int start = 0, end = i;
    while (end < n2)
    {
        count2[s2[start] - 'a']--;
        count2[s2[end] - 'a']++;

        if (count1 == count2)
            return true;

        start++, end++;
    }

    return false;
}

/*----------- Worst solution -----------*/

bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> mp;

    for (auto element : s1)
        mp[element]++;

    int count = mp.size();
    int i = 0, j = 0;
    int k = s1.length();

    while (j < s2.length())
    {
        // if element is matching
        if (mp.find(s2[j]) != mp.end())
        {
            mp[s2[j]]--;
            if (mp[s2[j]] == 0)
                count--;
        }
        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            if (count == 0)
                return true;

            if (mp.find(s2[i]) != mp.end())
            {
                mp[s2[i]]++;
                if (mp[s2[i]] == 1)
                    count++;
            }
            i++, j++;
        }
    }
    return false;
}

int main()
{
    cout << checkInclusion("adc", "dcda") << endl;
    return 0;
}