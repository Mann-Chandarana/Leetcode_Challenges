/*--------  Medium --------*/

/*- Naming a Company -*/

//////// Question number 2306.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/***** Time limit exceed ******/

// long long distinctNames(vector<string> &ideas)
// {
//     unordered_map<string, int> mp;

//     for (auto element : ideas)
//     {
//         mp[element]++;
//     }

//     ll n = ideas.size(), ans = 0;

//     for (ll i = 0; i < n - 1; i++)
//     {
//         for (ll j = i + 1; j < n; j++)
//         {
//             string a = ideas[i];
//             string b = ideas[j];
//             swap(a[0], b[0]);
//             if (mp.find(a) == mp.end() and mp.find(b) == mp.end())
//                 ans += 2;
//         }
//     }
//     return ans;
// }

/***** Using sets ******/

long long distinctNames(vector<string> &ideas)
{
    unordered_set<string> map[26];
    for (string &name : ideas)
    {
        map[name[0] - 'a'].insert(name.substr(1));
    }
    long long res = 0;
    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            int total1 = 0, total2 = 0;
            for (auto &substring : map[i])
            {
                if (map[j].find(substring) == map[j].end())
                {
                    total1++;
                }
            }
            for (auto &substring : map[j])
            {
                if (map[i].find(substring) == map[i].end())
                {
                    total2++;
                }
            }
            res += total1 * total2;
        }
    }
    return res * 2;
}

int main()
{
    vector<string> ideas = {"coffee", "donuts", "time", "toffee"};
    cout << distinctNames(ideas) << endl;
    return 0;
}