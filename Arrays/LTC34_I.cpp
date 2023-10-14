//////// Question number 1037.

#include <bits/stdc++.h>
using namespace std;

/* Comparing slope of all the point and if slope comes same then it is a straight line */

bool isBoomerang(vector<vector<int>> &points)
{
    int L1 = (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]);
    int L2 = (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]);
    if (L1 == L2)
    {
        return false;
    }

    return true;
}

int main()
{
    return 0;
}