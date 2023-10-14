/*--------  Hard --------*/

/*- Count All Valid Pickup and Delivery Options -*/

//////// Question number 1359.

#include <bits/stdc++.h>
using namespace std;

const int MOD = (1e9 + 7);

/********** Approach -1 **********/

int countOrders(int n)
{
    if (n == 1)
        return 1;

    int result = 1;

    for (int i = 2; i <= n; i++)
    {
        int spaces = (((i - 1) * 1LL * 2) % MOD + 1) % MOD;
        int curpos = ((spaces * 1LL * ((spaces + 1) / 2))) % MOD;
        result = (curpos * 1LL * result) % MOD;
    }
    return result;
}

/********** Approach -2 **********/

int factorial(int n)
{
    int fact = 1;

    for (int i = 2; i <= n; i++)
        fact = (fact * 1LL * i) % MOD;

    return fact;
}

int countOrders(int n)
{
    int result = 1, multiplier = 1;

    for (int i = 0; i < n; i++)
    {
        result = (result * 1LL * multiplier) % MOD;
        multiplier += 2;
    }

    result = (result * 1LL * factorial(n)) % MOD;

    return result;
}

int main()
{
    cout << 90 % MOD << endl;
    cout << countOrders(3) << endl;
    return 0;
}