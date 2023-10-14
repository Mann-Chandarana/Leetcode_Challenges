/*-------- Medium -----------*/

/*- Minimum Number of Arrows to Burst Balloons -*/

//////// Question number 452.

#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [&](vector<int> vec1, vector<int> vec2)
    {
      return (vec1[1] < vec2[1]);
    });


    int no_arrow = 1, en = points[0][1];

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > en)
        {
            no_arrow++;
            en = points[i][1];
        }
        else
        {
            en = min(points[i][1], en);
        }
    }
    return no_arrow;
}

int main()
{
    vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    cout << findMinArrowShots(points) << endl;

    return 0;
}