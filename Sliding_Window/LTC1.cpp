///// Important question

/*-------- Hard -----------*/

/*- Minimum window substring -*/

//////// Question number 76.

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int j = 0, i = 0;

    unordered_map<char, int> freq_t;

    for (auto ch : t)
    {
        freq_t[ch]++;
    }

    int count = freq_t.size();
    int min_length = INT_MAX;
    int start = 0;

    while (j < s.size())
    {
        if (freq_t.find(s[j]) != freq_t.end())
        {
            freq_t[s[j]]--;
            if (freq_t[s[j]] == 0)
            {
                count--;
            }
        }

        if (count == 0)
        {
            while (count == 0)
            {
                if (min_length > j - i + 1)
                {
                    min_length = j - i + 1;
                    start = i;
                }

                if (freq_t.find(s[i]) != freq_t.end())
                {
                    if (freq_t[s[i]] == 0)
                    {
                        count++;
                    }
                    freq_t[s[i]]++;
                }
                i++;
            }
        }
        j++;
    }
    if (min_length == INT_MAX)
    {
        return "";
    }

    return s.substr(start, min_length);
}

int main()
{
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}