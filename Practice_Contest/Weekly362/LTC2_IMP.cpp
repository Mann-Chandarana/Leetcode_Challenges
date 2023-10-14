/*--------  Medium --------*/

/*- Determine if a Cell Is Reachable at a Given Time -*/

//////// Question number 2849.

#include <bits/stdc++.h>
using namespace std;

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
{
    int xdiff = abs(sx - fx), ydiff = abs(sy - fy);

    if (xdiff == 0 and ydiff == 0 and t == 1) /// edge case
        return false;

    int diagonalDistance = min(xdiff, ydiff);
    int remaing_distance_after_movingdiagonally = abs(xdiff - ydiff);

    return (diagonalDistance + remaing_distance_after_movingdiagonally)<=t;
}

int main()
{
    return 0;
}