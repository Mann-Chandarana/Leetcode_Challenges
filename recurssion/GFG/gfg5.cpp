// Find all factorial numbers less than or equal to N :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

long long fact(long long N)
{
    if (N == 0)
    {
        return 1;
    }
    return N * fact(N - 1);
}

vector<long long> factorialNumbers(long long N)
{
    long long a = 1;
    int i = 1;
    vector<long long> v;

    while (a * i <= N)
    {
        a = a * i;
        v.push_back(a);
        i++;
    }

    return v;
}

int main()
{
    return 0;
}