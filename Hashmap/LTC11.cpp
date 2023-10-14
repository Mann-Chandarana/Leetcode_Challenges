#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define mpii unordered_map<int, int>
#define vpii vector<pair<int, int>>
#define miv unordered_map<int, vector<int>>

/* Without using Hash set */

int minDeletions(string s)
{
    vector<int> freq(26, 0);
    int n = s.length();

    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    int count = 0;

    sort(all(freq));

    for (int i = 24; i >= 0 and freq[i] > 0; i--)
    {
        if (freq[i] >= freq[i + 1])
        {
            int prev = freq[i];
            freq[i] = max(0, freq[i + 1] - 1);

            count += (prev - freq[i]);
        }
    }

    return count;
}

/* Using Hashset */

int minDeletions(string s)
{
    vector<int> freq(26, 0);
    int n = s.length();

    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    int count = 0;

    unordered_set<int> st;

    for (int i = 0; i < 26; i++)
    {
        while (freq[i] > 0 and st.find(freq[i]) != st.end())
        {
            freq[i]--;
            count++;
        }
        st.insert(freq[i]);
    }

    return count;
}

int main()
{
    cout << minDeletions("aaabbbccc") << endl;
    return 0;
}