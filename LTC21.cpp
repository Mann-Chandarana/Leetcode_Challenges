/* 1160. Find Words That Can Be Formed by Characters */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int countCharacters(vector<string> &words, string chars)
{
    int n = words.size(), len = 0;
    vector<int> freq(26, 0);

    for (auto ch : chars)
        freq[ch - 'a']++;

    for (int i = 0; i < n; i++)
    {
        vector<int> freq1(26, 0);
        bool answer = true;

        for (auto ch : words[i])
            freq1[ch - 'a']++;

        for (int j = 0; j < 26; j++)
        {

            if (freq1[j] != 0)
            {
                if (freq[j] < freq1[j])
                {
                    answer = false;
                    break;
                }
            }
        }
        if (answer)
            len += words[i].length();
    }
    return len;
}

int main()
{
    return 0;
}