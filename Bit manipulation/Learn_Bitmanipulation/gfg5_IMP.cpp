/* Geeks for Geeks :- Count the number of set bits */

#include <bits/stdc++.h>
using namespace std;

/* Approach - 1 */

int countSetBits(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        while (num)
        {
            if (num & 1)
                count++;
            num = num >> 1;
        }
    }

    return count;
}

/* Optimised approach */

int countSetBits(int n)
{
    int ans = 0;
    while (n)
    {
        int x = 1;
        while (n >= x)
        {
            x = (x << 1);
        }

        x = x >> 1;

        ans += log2(x) * (x / 2) + (n - x + 1);
        n -= x;
    }

    return ans;
}

int main()
{
    return 0;
}