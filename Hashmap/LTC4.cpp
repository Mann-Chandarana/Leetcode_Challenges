/* 290. Word Pattern */


#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    vector<string> word;
    string ans = "";
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] == ' ' or i==s.length())
        {
            word.push_back(ans);
            ans = "";
            continue;
        }
        ans += s[i];
    }

    if (word.size() != pattern.size())
    {
        return false;
    }
    unordered_map<char, string> mp;
    unordered_set<string> st;

    for (int i = 0; i < pattern.length(); i++)
    {
        if (mp.find(pattern[i]) != mp.end())
        {
            if (mp[pattern[i]] != word[i])
            {
                return false;
            }
        }
        else
        {
            if (st.count(word[i]) > 0)
            {
                return false;
            }

            mp[pattern[i]] = word[i];
            st.insert(word[i]);
        }
    }
    return true;
}

// bool wordPattern(string pattern, string s)
// {
//     unordered_map<char, string> mp;
//     int j = 0;

//     string ans = "";
//     for (int i = 0; i <= s.length(); i++)
//     {
//         if (s[i] == ' ' or i == s.length())
//         {
//             if (mp.find(pattern[j]) != mp.end())
//             {
//                 if (mp[pattern[j]] == ans)
//                 {
//                     ans = "";
//                     j++;
//                     continue;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 for (auto element : mp)
//                 {
//                     if (element.second == ans && element.first != pattern[j])
//                     {
//                         return false;
//                     }
//                 }
//                 mp[pattern[j++]] = ans;
//                 ans = "";
//             }
//         }
//         else
//         {
//             ans += s[i];
//         }
//     }
//     if (j != pattern.length())
//     {
//         return false;
//     }

//     return true;
// }

int main()
{
    cout << wordPattern("abba", "dog cat cat fish") << endl;
    return 0;
}