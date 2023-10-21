/*--------  Medium --------*/

/*- Remove Duplicate Letters -*/

//////// Question number 316.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

string removeDuplicateLetters(string s)
{
    int n = s.length();

    vector<int> taken(26, false);
    vector<int> lastIndex(26);

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        lastIndex[ch - 'a'] = i;
    }

    string result;

    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'a';

        if (taken[idx])
            continue;

        while (result.size() > 0 and (s[i] < result.back() and lastIndex[result.back() - 'a'] > i))
        {
            taken[result.back() - 'a'] = false;
            result.pop_back();
        }
        result.push_back(s[i]);
        taken[idx] = true;
    }

    return result;
}

int main()
{
    return 0;
}