///// Important question

/*--------Medium-----------*/

/*- Image overlap -*/

//////// Question number 835.

#include <bits/stdc++.h>
using namespace std;

int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{
    int n = img1.size();
    vector<pair<int, int>> vec_a, vec_b;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (img1[i][j] == 1)
            {
                vec_a.push_back({i, j});
            }
            if (img2[i][j] == 1)
            {
                vec_b.push_back({i, j});
            }
        }
    }
    int ans = 0;
    map<pair<int, int>, int> mp;

    for (auto i : vec_a)
    {
        for (auto j : vec_b)
        {
            mp[{i.first - j.first, i.second - j.second}]++;
            ans = max(ans, mp[{i.first - j.first, i.second - j.second}]);
        }
    }

    return ans;
}

// int check(vector<vector<int>> img1, vector<vector<int>> img2, int shift_x, int shift_y)
// {
//     int n = img1.size();
//     int num = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i + shift_x >= 0 and i + shift_x < n and j + shift_y >= 0 and j + shift_y < n and img1[i + shift_x][j + shift_y] == 1 and img2[i][j] == 1)
//                 num++;
//         }
//     }
//     return num;
// }
// int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
// {
//     int n = img1.size();
//     int out = INT_MIN;
//     for (int x = -n; x < n; x++)
//     {
//         for (int y = -n; y < n; y++)
//         {
//             out = max(out, check(img1, img2, x, y));
//         }
//     }
//     return out;
// }

int main()
{
    vector<vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    cout << largestOverlap(img1, img2) << endl;
    return 0;
}