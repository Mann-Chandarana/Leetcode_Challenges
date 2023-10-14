#include <bits/stdc++.h>
using namespace std;

/* Floor in a sorted array */

int findFloor(vector<long long> v, long long n, long long x)
{
    long long low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

/* Ceil in a sorted array */

int findCeil(vector<long long> v, long long n, long long x)
{
    long long low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    return 0;
}