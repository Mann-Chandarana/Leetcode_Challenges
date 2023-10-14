/*-------- Medium -----------*/

/*-  Word Break -*/

//////// Question number 139.

#include <bits/stdc++.h>
using namespace std;

// unordered_map<string, bool> memo;

// bool solve(string word, unordered_map<string, bool> mp)
// {
//     if (mp.find(word) != mp.end())
//         return true;

//     if (memo.find(word) != mp.end())
//         return memo[word];

//     for (int i = 0; i < word.length(); i++)
//     {
//         string left = word.substr(0, i + 1);
//         string right = word.substr(i + 1);

//         if (mp.find(left) != mp.end())
//         {
//             memo[word] = true;
//             if (solve(right, mp))
//                 return true;
//         }
//     }
//     memo[word] = false;
//     return false;
// }

// bool wordBreak(string s, vector<string> &wordDict)
// {
//     unordered_map<string, bool> mp;
//     for (auto element : wordDict)
//     {
//         mp[element] = true;
//     }

//     return solve(s, mp);
// }

/*********** Main recursion and memorization *************/

// unordered_set<string> st;

// bool solve(string s, int index, int n, vector<int> &dp)
// {
//     if (index == n)
//         return true;

//     if (dp[index] != -1)
//         return dp[index];

//     for (int i = index; i < n; i++)
//     {
//         string temp = s.substr(index, i - index + 1);
//         if (st.count(temp))
//         {
//             if (solve(s, i + 1, n, dp))
//                 return dp[index] = true;
//         }
//     }

//     return dp[index] = false;
// }

// bool wordBreak(string s, vector<string> &wordDict)
// {
//     int n = s.size();

//     for (auto word : wordDict)
//     {
//         st.insert(word);
//     }
//     vector<int> dp(n, -1);

//     return solve(s, 0, n, dp);
// }

/*********** Space optimization ***************/

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st;
    int n = s.size();

    for (auto word : wordDict)
    {
        st.insert(word);
    }
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int index = n-1; index >= 0; index--)
    {
        for (int i = index; i < n; i++)
        {
            string temp = s.substr(index, i - index + 1);
            cout << temp << endl;
            if (st.count(temp))
            {
                cout << "Hi" << endl;
                cout<<index+1<<endl;
                break;
                if (dp[i + 1])
                    dp[index] = true;
            }
        }
    }

    for (auto element : dp)
    {
        cout << element << " ";
    }
    cout << endl;

    return dp[0];
}

int main()
{
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak("leetcode", wordDict);
    return 0;
}