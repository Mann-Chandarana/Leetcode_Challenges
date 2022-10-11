//////// Question number 1408.

#include <bits/stdc++.h>
using namespace std;

vector<string> stringMatching(vector<string> &words)
{
    vector<string> ans;
    for (auto &s : words)
    {
        for (auto &w : words)
        {
            if (w == s)
                continue;
            if (w.find(s) != -1)
            {
                ans.push_back(s);
                break;
            }
        }
    }
    return ans;
}

// bool contains(string short_str, string long_str)
// {
//     int j = 0;
//     for (int i = 0; i < long_str.length(); i++)
//     {
//         if (short_str[j] == long_str[i])
//         {
//             int k = i;
//             while (long_str[k] == short_str[j] and k + 1 < long_str.length() and j + 1 < short_str.length())
//             {
//                 k++;
//                 j++;
//                 if (short_str[j] != long_str[k])
//                 {
//                     j--;
//                     break;
//                 }
//             }
//             if (j == short_str.length() - 1)
//             {
//                 return true;
//             }
//             else
//             {
//                 j = 0;
//             }
//         }
//     }
//     return false;
// }

// vector<string> stringMatching(vector<string> &words)
// {
//     vector<string> answer;
//     set<string> ans;
//     for (int i = 0; i < words.size(); i++)
//     {
//         for (int j = 0; j < words.size(); j++)
//         {
//             if (words[i] == words[j])
//             {
//                 continue;
//             }

//             if (words[j].length() >= words[i].length() and contains(words[i], words[j]))
//             {
//                 ans.insert(words[i]);
//             }
//         }
//     }
//     for (auto element : ans)
//     {
//         answer.push_back(element);
//     }

//     return answer;
// }


int main()
{
    vector<string> words = {"mass", "as", "hero", "superhero"};
    words = stringMatching(words);

    for (auto ele : words)
    {
        cout << ele << endl;
    }

    return 0;
}