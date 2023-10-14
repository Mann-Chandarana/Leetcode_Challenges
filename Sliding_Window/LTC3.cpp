/*--------  Medium --------*/

/*- Find All Anagrams in a String -*/

//////// Question number 438.

#include <bits/stdc++.h>
using namespace std;

/*----------- Best solution -----------*/

vector<int> findAnagrams(string s, string p)
{
    vector<int> cur(26), goal(26), answer;
    for (auto c : p)
        goal[c - 'a']++;

    for (int i = 0; i < s.length(); i++)
    {
        cur[s[i] - 'a']++;
        if (i >= p.length())
            cur[s[i - p.size()] - 'a']--;
        if (goal == cur)
            answer.push_back(i-p.size()+1);
    }
    return answer;
}

/*----------- Average solution -----------*/

vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> mp;
    vector<int> answer;
    for (auto element : p)
        mp[element]++;

    int count = mp.size();
    int i = 0, j = 0, k = p.length();

    while (j < s.length())
    {
        // if(element is matching)

        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
        }
        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            if (count == 0)
                answer.push_back(i);

            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                    count++;
            }
            i++, j++;
        }
    }
    return answer;
}

int main()
{
    vector<int> answer = findAnagrams("abab", "ab");
    for (auto element : answer)
    {
        cout << element << " ";
    }
    return 0;
}