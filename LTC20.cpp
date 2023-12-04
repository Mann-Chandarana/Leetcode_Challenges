/** 1266. Minimum Time Visiting All Points **/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int timeto(vector<int> &a, vector<int> &b)
{
    int dx = abs(a[0] - b[0]);
    int dy = abs(a[1] - b[1]);

    int answer = min(dx, dy) + abs(dx - dy);
    return answer;
}

int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int n = points.size();

    int time = 0;

    for (int i = 0; i < n - 1; i++)
        time += timeto(points[i], points[i + 1]);

    return time;
}

int main()
{
    return 0;
}