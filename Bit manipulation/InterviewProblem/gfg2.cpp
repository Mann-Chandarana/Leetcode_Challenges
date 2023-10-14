/* Geeks for Geeks :- Two numbers with odd occurrences */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<long long int> twoOddNum(long long int Arr[], long long int N)
{
    // code here
    int res1 = 0;
    int res2 = 0;
    int _xor = 0;

    for (int i = 0; i < N; ++i)
        _xor ^= Arr[i];

    // find the right most set bit
    _xor = (_xor & (~(_xor - 1)));

    for (int i = 0; i < N; ++i)
    {
        if (Arr[i] & _xor)
            res1 ^= Arr[i];
        else
            res2 ^= Arr[i];
    }
    if (res2 > res1)
        return {res2, res1};
    return {res1, res2};
}

int main()
{
    return 0;
}