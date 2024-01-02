/* 1897. Redistribute Characters to Make All Strings Equal */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

bool makeEqual(vector<string> &words)
{
    int n = words.size();
    vector<int> freq(26, 0);

    for (auto str : words)
    {
        for (auto ch : str)
            freq[ch - 'a']++;
    }

    auto lambda = [&](int a)
    {
        return a % n == 0;
    };

    return all_of(all(freq), lambda);
}

int main()
{
    return 0;
}