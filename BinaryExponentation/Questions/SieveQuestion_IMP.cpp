/* https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/?purpose=login&source=problem-page&update=google */

/* https://www.youtube.com/watch?v=rrH3nZ9KjCY&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=80 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

bool isVowel(char &ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

vector<string> subset(string s)
{
    int sz = (1 << s.size());

    vector<string> ans;
    for (int mask = 0; mask < sz; mask++)
    {
        string subset;
        for (int bit = 0; bit < s.size(); bit++)
        {
            if (mask & (1 << bit))
                subset.push_back(s[bit]);
        }
        if (subset.size() != 0)
            ans.push_back(subset);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<string> str(n);

        for (int i = 0; i < n; i++)
            cin >> str[i];

        unordered_map<string, int> hsh;

        for (int i = 0; i < n; i++)
        {
            set<char> distint_vw;
            for (char ch : str[i])
            {
                if (isVowel(ch))
                    distint_vw.insert(ch);
            }
            string vowel_str;
            for (char ch : distint_vw)
                vowel_str.push_back(ch);

            vector<string> all_subsets = subset(vowel_str);
            for (string vowel_subset : all_subsets)
                hsh[vowel_subset]++;
        }
        long long ans = 0;

        for (auto &pr : hsh)
        {
            if (pr.second < 3)
                continue;

            long long ct = pr.second;
            long long ways = (ct * (ct - 1) * (ct - 2)) / 6;

            if (pr.first.size() % 2 == 0)
                ans -= ways;
            else
                ans += ways;
        }

        cout << ans << endl;
    }

    return 0;
}