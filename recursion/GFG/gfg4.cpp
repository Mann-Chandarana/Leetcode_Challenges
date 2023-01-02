// Sum of first n terms :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

long long sumOfSeries(long long N)
{
    static long long sum = 0;
    if (N == 0)
    {
        return sum;
    }
    sumOfSeries(N - 1);
    sum += (pow(N, 3));
}

long long sumOfSeries(long long N)
{
    long long sum = (N * (N + 1)) / 2;

    return sum * sum;
}

int main()
{
    cout << sumOfSeries(7) << endl;
    return 0;
}