/*-------- Hard -----------*/

/*- Concatenated Words -*/

//////// Question number 472.

#include <bits/stdc++.h>
using namespace std;

/****** Using Recursion *******/

// unordered_map<string, bool> mp;

// bool isConcated(string word, unordered_set<string> &st)
// {
//     if (mp.find(word) != mp.end())
//         return mp[word];

//     int l = word.length();

//     for (int i = 0; i < l; i++)
//     {
//         string prefix = word.substr(0, i + 1);
//         string suffix = word.substr(i + 1);

//         if ((st.find(prefix) != st.end() && isConcated(suffix, st)) ||
//             (st.find(prefix) != st.end() && st.find(suffix) != st.end()))
//             return mp[word] = true;
//     }
//     return mp[word] = false;
// }

// vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
// {
//     int n = words.size();
//     mp.clear();
//     unordered_set<string> st(begin(words), end(words));
//     vector<string> ans;
//     for (int i = 0; i < n; i++)
//     {
//         if (isConcated(words[i], st))
//             ans.push_back(words[i]);
//     }
//     return ans;
// }

/****** Using iteration  *******/

vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    unordered_set<string> word_set(words.begin(), words.end());
    vector<string> ans;
    for (auto w : words)
    {
        int n = w.size();
        vector<bool> dp(n + 1, false);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!dp[i])
                continue;
            for (int j = i + 1; j <= n; j++)
            {
                if (j - i < n and word_set.count(w.substr(i, j - i)))
                    dp[j] = 1;
            }
        }
        if (dp[n] == 1)
            ans.push_back(w);
    }
    return ans;
}

int main()
{
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> ans = findAllConcatenatedWordsInADict(words);

    for (string temp : ans)
    {
        cout << temp << endl;
    }
    return 0;
}