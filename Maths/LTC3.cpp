/******* 326. Power of Three *******/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach -1) */

bool isPowerOfThree(int n)
{
    if (n <= 0)
        return 0;

    double x = (log10(n) / log10(3));

    return ceil(x) == floor(x);
}

/* Approach -2) */

bool isPowerOfThree(int n)
{
    if (n <= 0)
        return 0;

    return (1162261467 % n == 0);
}

/* Approach -3) :- Recurison */

bool isPowerOfThree(int n)
{
    if (n <= 0)
        return false;

    else if (n == 1)
        return true;

    return ((n % 3 == 0) and isPowerOfThree(n / 3));
}

/* Approach -4) :- Iteration */

bool isPowerOfThree(int n)
{
    if (n == 0)
        return false;

    while (n % 3 == 0)
        n /= 3;

    return n == 1;
}

int main()
{
    return 0;
}