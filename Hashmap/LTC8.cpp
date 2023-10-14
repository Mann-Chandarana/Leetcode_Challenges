// 953. Verifying an Alien Dictionary

#include <bits/stdc++.h>
using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
    int n = words.size();
    unordered_map<char, int> mp;
    int i = 0;

    for (auto element : order)
        mp[element] = i++;

    for (int i = 0; i < n - 1; i++)
    {
        string w1 = words[i], w2 = words[i + 1];

        for (int j = 0; j < w1.length(); j++)
        {
            if (j == w2.length())
                return false;

            if (w1[j] != w2[j])
            {
                if (mp[w2[j]] < mp[w1[j]])
                    return false;
                break;
            }
        }
    }

    return true;
}

int main()
{
    vector<string> words = {"kuvp", "q"};
    cout << isAlienSorted(words, "ngxlkthsjuoqcpavbfdermiywz") << endl;
    return 0;
}