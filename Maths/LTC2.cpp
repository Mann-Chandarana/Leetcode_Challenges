/******** 342. Power of Four ********/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach -1) */

bool isPowerOfFour(int n)
{
    if (n <= 0)
        return 0;

    double x = log10(n) / log10(4);

    return ceil(x) == floor(x);
}

/* Approach -2) */

bool isPowerOfFour(int n)
{
    if (n <= 0)
        return 0;

    if ((n & n - 1) == 0 and ((n - 1) % 3 == 0))
        return true;

    return false;
}

/* Approach -3) */

bool isPowerOfFour(int n)
{
    if (n <= 0)
        return 0;

    int x = (log(n) / log(4));

    if (pow(4, x) == n)
        return true;

    return false;
}

int main()
{
    return 0;
}