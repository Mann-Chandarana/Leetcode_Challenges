/*-------- Medium -----------*/

/*- Sort Characters By Frequency  -*/

//////// Question number 451.

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> mp;

    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    priority_queue<pair<int, int>> pq;

    for (auto element : mp)
        pq.push({element.second, element.first});

    string answer = "";

    while (!pq.empty())
    {
        int iteration = pq.top().first;
        char ch = pq.top().second;
        pq.pop();

        for (int i = 0; i < iteration; i++)
            answer += ch;
    }
    return answer;
}

int main()
{
    return 0;
}