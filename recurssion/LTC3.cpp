/* 509. Fibonacci Number */

#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int var1 = 0, var2 = 1, var3;
    for (int i = 2; i <=n; i++)
    {
        var3 = var1 + var2;
        var1 = var2;
        var2 = var3;
    }
    return var3;
}


int main()
{
    cout << fib(4) << endl;
    return 0;
}