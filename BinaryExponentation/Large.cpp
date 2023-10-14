#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e18 + 7;

// Time complexity log^2(n)

/* When a and m is large     */

int binExpIter(int a, int b)
{
    int ans = 1;

    while (b)
    {
        if (b & 1)
            ans = binExpIter(ans, a) % M;

        a = binExpIter(a, a);
        b >>= 1;
    }
    return ans;
}

long long binMultiply(long long a, long long b)
{
    long long ans = 0;

    while (b > 0)
    {
        if (b & 1)
            ans = (ans + a) % M;

        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

/* when b is very large */

int binExpIter(int a, int b, int m)
{
    int ans = 1;

    while (b)
    {
        if (b & 1)
            ans = binExpIter(ans, a) % m;

        a = binExpIter(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    int m = 1e9 + 7;
    // when m is prime
    cout << binExpIter(50, binExpIter(64, 32, m - 1), m);
    return 0;
}