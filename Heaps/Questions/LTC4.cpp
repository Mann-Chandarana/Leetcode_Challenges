/*--------Medium-----------*/

/*- Reorganize String -*/

//////// Question number 767.

#include <bits/stdc++.h>
using namespace std;

// Using Array sort

string reorganizeString(string s)
{
    int n = s.length();
    vector<int> freq(26, 0);

    char maxfreqch;
    int maxi = INT_MIN;

    for (auto ch : s)
    {
        freq[ch - 'a']++;
        if (freq[ch - 'a'] > maxi)
        {
            maxi = freq[ch - 'a'];
            maxfreqch = ch;
        }

        if (freq[ch - 'a'] > (n + 1) / 2)
            return "";
    }

    string answer = s;
    int i = 0;
    while (freq[maxfreqch - 'a'] != 0)
    {
        answer[i] = maxfreqch;
        i += 2;
        freq[maxfreqch - 'a']--;
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        while (freq[ch - 'a'] > 0)
        {
            if (i >= n)
                i = 1;

            answer[i] = ch;
            i += 2;
            freq[ch - 'a']--;
        }
    }
    return answer;
}

// Using Max-heap

string reorganizeString(string s)
{
    unordered_map<char, int> mp;

    for (auto c : s)
        mp[c]++;

    priority_queue<pair<int, char>> pq;

    for (auto element : mp)
        pq.push({element.second, element.first});

    string answer = "";

    while (pq.size() >= 2)
    {
        auto [freq1, char1] = pq.top();
        pq.pop();

        auto [freq2, char2] = pq.top();
        pq.pop();

        answer += char1;
        answer += char2;

        if (--freq1 > 0)
            pq.push({freq1, char1});

        if (--freq2 > 0)
            pq.push({freq2, char2});
    }

    if (!pq.empty())
    {
        auto [freq, ch] = pq.top();
        pq.pop();

        if (freq > 1)
            return "";

        answer += ch;
    }
    return answer;
}

int main()
{
    return 0;
}