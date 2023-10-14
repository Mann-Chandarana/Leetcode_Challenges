#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

/*Using recursion */

int binExpRecur(int a, int b)
{
    if (b == 0)
        return 1;

    long res = binExpRecur(a, (b / 2));

    if (b & 1)
        return (a * (res * 1LL * res) % MOD) % MOD;

    else
        return (res * 1LL * res) % MOD;
}

/* Using Iterative code */

int binExpIter(int a, int b)
{
    int ans = 1;

    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % MOD;
        a = (a * 1LL * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    return 0;
}