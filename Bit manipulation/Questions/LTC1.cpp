/*--------  Medium --------*/

/*- Divide Two Integers -*/

//////// Question number 29.

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;

    bool isPositive = (dividend < 0 == divisor < 0);

    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);

    unsigned int ans = 0;

    for (int i = 31; i >= 0; i--)
    {
        if ((b << i) < a)
        {
            a -= (b << i);
            ans += (b << i);
        }
    }

    if (ans == 1 << 31 and isPositive)
        return INT_MAX;

    return isPositive ? ans : -ans;
}

int divide(int n, int m)
{
    if (n == INT_MIN && m == -1)
        return INT_MAX;
    if (n == INT_MIN && m == 1)
        return n;
    int sign = (n < 0) ^ (m < 0);
    long long nn = abs(n), mm = abs(m), now = 0, ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (now + (mm << i) <= nn)
        {
            ans |= 1 << i;
            now += (mm << i);
        }
    }
    return (sign ? -ans : ans);
}

int main()
{
    return 0;
}