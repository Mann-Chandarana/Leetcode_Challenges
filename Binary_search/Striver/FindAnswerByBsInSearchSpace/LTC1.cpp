/* 69. Sqrt(x) */

#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    int s = 0, e = x, ans;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (mid * mid == x)
            return mid;

        else if (mid * mid < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    return 0;
}