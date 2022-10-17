/*--------Medium-----------*/

/*- Find Players With Zero or One Losses -*/

//////// Question number 2225.

#include <bits/stdc++.h>
using namespace std;

/******************** Another approach ************************/

// vector<vector<int>> findWinners(vector<vector<int>> &matches)
// {
//     unordered_map<int, int> umap;
//     vector<vector<int>> result(2);
//     for (int i = 0; i < matches.size(); i++)
//     {
//         umap[matches[i][1]]++;
//     }
//     for (auto i = umap.begin(); i != umap.end(); i++)
//     {
//         if (i->second == 1)
//         {
//             result[1].push_back(i->first);
//         }
//     }


//     for (int i = 0; i < matches.size(); i++)
//     {
//         if (umap[matches[i][0]] == 0)
//         {
//             result[0].push_back(matches[i][0]);
//             umap[matches[i][0]] = 1;
//         }
//     }

//     sort(result[0].begin(), result[0].end());

//     sort(result[1].begin(), result[1].end());

//     return result;
// }

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    map<int, pair<int, int>> mp;

    for (int i = 0; i < matches.size(); i++)
    {
        mp[matches[i][0]].first++;
        mp[matches[i][1]].second++;
    }

    vector<vector<int>> answer(2);

    for (auto element : mp)
    {
        if (element.second.second == 0)
        {
            answer[0].push_back(element.first);
        }
        if (element.second.second == 1)
        {
            answer[1].push_back(element.first);
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    matches = findWinners(matches);
    return 0;
}