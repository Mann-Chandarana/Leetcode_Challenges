/*--------  Medium --------*/

/*- Unique Length-3 Palindromic Subsequences -*/

//////// Question number 1930.

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define ll long long
#define all(v) v.begin(), v.end()

int countPalindromicSubsequence(string s)
{
    int n = s.length();

    vector<pi> index(26, {-1, -1});

    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'a';

        if (index[idx].first == -1)
            index[idx].first = i;

        index[idx].second = i;
    }

    int result = 0;

    for (int i = 0; i < 26; i++)
    {
        if (index[i] != make_pair(-1, -1))
        {
            unordered_set<char> st;
            for (int middle = index[i].first + 1; middle < index[i].second; middle++)
                st.insert(s[middle]);

            result += st.size();
        }
    }
    return result;
}

int main()
{
    return 0;
}