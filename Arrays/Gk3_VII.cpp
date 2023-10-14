/* Geeks for Geeks :- Find maximum sum of the smallest two number in the subarray */

#include <bits/stdc++.h>
using namespace std;

long long pairWithMaxSum(long long arr[], long long N)
{
    long long maxi = INT_MIN;

    for (long long i = 0; i < N - 1; i++)
        maxi = max(maxi, arr[i] + arr[i + 1]);

    return maxi;
}

int main()
{
    return 0;
}