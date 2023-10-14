/* 231. Power of Two */

#include <bits/stdc++.h>
using namespace std;

/* Approach-1 */

bool isPowerOfTwo(int n)
{
    int ans = 1;

    for (int i = 0; i <= 30; i++)
    {
        if (ans == n)
            return 1;

        if (ans < INT_MAX / 2)
            ans *= 2;
    }
    return ans;
}

/* Approach -2 */

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    return ((n & (n - 1)) == 0);
}

int main()
{
    return 0;
}