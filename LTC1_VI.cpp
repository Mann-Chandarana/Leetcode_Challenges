/*--------  Hard --------*/

/*- Max Points on a Line -*/

//////// Question number 149.

#include <bits/stdc++.h>
using namespace std;

/* Approach -1) */

/* O(n^3) */

int maxPoints(vector<vector<int>> points)
{
    if (points.size() <= 2)
        return points.size();

    int maxi = 0;
    int n = points.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x1 = points[i][0], x2 = points[j][0];
            int y1 = points[i][1], y2 = points[j][1];

            int total = 2;

            for (int k = 0; k != i and k < n and k != j; k++)
            {
                int x = points[k][0], y = points[k][1];
                if ((y2 - y1) * (x - x1) == (x2 - x1) * (y - y1))
                    total++;
            }
            maxi = max(maxi, total);
        }
    }

    return maxi;
}

/* Approach -2) */

/* O((n^2)logn) */

int maxPoints(vector<vector<int>> &points)
{
    int ans = 1;
    int n = points.size(), same_point = 0;

    for (int i = 0; i < n - 1; i++)
    {
        unordered_map<double, int> mp;
        for (int j = i + 1; j < n; j++)
        {
            if (points[j][0] == points[i][0] and points[j][1] == points[i][1])
            {
                same_point++;
            }
            else if (points[j][0] == points[i][0])
            {
                mp[INT_MAX]++;
            }
            else
            {
                double slope = double(points[j][1] - points[i][1]) / double(points[j][0] - points[i][0]);
                mp[slope]++;
            }
        }
        int temp = 0;
        for (auto element : mp)
        {
            temp = max(element.second + 1, temp);
        }
        ans = max(temp + same_point, ans);
        same_point = 0;
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1, 1}, {1, 1}, {1, 1}, {2, 2}, {3, 3}};
    cout << maxPoints(points) << endl;
    return 0;
}