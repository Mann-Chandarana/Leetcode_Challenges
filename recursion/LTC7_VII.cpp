/*-------- Medium -----------*/

/*- Count Good Numbers -*/

//////// Question number 1922.

#include <bits/stdc++.h>
using namespace std;

int m = 1e9 + 7;

long long power(long long x, long long n)
{
    if (n == 0)
    {
        return 1;
    }
    return n % 2 == 0 ? power((x * x) % m, n / 2) : (x * power((x * x) % m, n / 2) % m);
}

int countGoodNumbers(long long n)
{
    long long no_4s = n / 2, no_5s = n - no_4s;

    long long answer = ((power(4, no_4s)) % m * (power(5, no_5s)) % m) % m;

    return (int)answer;
}

int main()
{
    cout << countGoodNumbers(50) << endl;
    return 0;
}