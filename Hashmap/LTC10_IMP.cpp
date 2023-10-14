/*-------- Medium -----------*/

/*- Group the People Given the Group Size They Belong To -*/

//////// Question number 1282.

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define mpii unordered_map<int, int>
#define vpii vector<pair<int, int>>
#define miv unordered_map<int, vector<int>>

/**** Approach-1 *****/

vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{
    int n = groupSizes.size();

    vector<vector<int>> answer;

    vector<vector<int>> mp(n + 1);

    for (int i = 0; i < n; i++)
    {
        int L = groupSizes[i];

        mp[L].push_back(i);

        if (mp[L].size() == L)
            answer.push_back(mp[L]), mp[L] = {};
    }

    return answer;
}

/**** Approach-2 *****/

vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{
    int n = groupSizes.size();

    vector<vector<int>> answer;

    miv mp;

    for (int i = 0; i < n; i++)
        mp[groupSizes[i]].push_back(i);

    for (auto element : mp)
    {
        vector<int> ans;
        for (int i = 0; i < (element.second).size(); i++)
        {
            if (ans.size() == element.first)
            {
                answer.push_back(ans);
                i--;
                ans.clear();
            }
            else
                ans.push_back((element.second)[i]);
        }
        if (ans.size() != 0)
            answer.push_back(ans);
    }

    return answer;
}

int main()
{
    vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
    groupThePeople(groupSizes);
    return 0;
}