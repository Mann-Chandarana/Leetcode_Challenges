/*--------Medium-----------*/

//////// Question number 1828.

#include <bits/stdc++.h>
using namespace std;

/********************** Brute force approach *******************************/

// vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
// {
//     vector<int> res;
//     for (auto &q : queries)
//     {
//         int cnt = 0, rr = q[2];
//         for (auto &p : points)
//         {
//             int distance = pow((q[0] - p[0]), 2) + pow((q[1] - p[1]), 2);
//             if (sqrt(distance) <= rr)
//             {
//                 cnt++;
//             }
//         }
//         res.push_back(cnt);
//     }
//     return res;
// }


/********************** Using binary serach for reducing time complexity of a given algorithm *******************************/

int sqr(int a)
{
    return a * a;
}

// find lower bound of left boundry
int find_left_boundry_index(vector<vector<int>> &points, int x_center, int y_center, int r)
{

    int lo = 0, hi = points.size();

    while (lo < hi)
    {

        int mi = lo + (hi - lo) / 2;

        if (x_center - r <= points[mi][0])
            hi = mi;
        else
            lo = mi + 1;
    }
    return hi;
}
vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
{

    sort(points.begin(), points.end());
    vector<int> ans;

    for (int i = 0; i < queries.size(); i++)
    {

        int x_center = queries[i][0], y_center = queries[i][1], r = queries[i][2];
        int index = find_left_boundry_index(points, x_center, y_center, r);
        int count = 0;

        for (int j = index; j < points.size() and points[j][0] <= x_center + r; j++)
        {

            int x = points[j][0];
            int y = points[j][1];
            // square of distance from center
            count += sqr(x_center - x) + sqr(y_center - y) <= r * r;
        }

        ans.push_back(count);
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1, 3}, {3, 3}, {5, 3}, {2, 2}}, queries = {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};
    vector<int> answer = countPoints(points, queries);

    for (auto element : answer)
    {
        cout << element << " ";
    }

    return 0;
}