/* Geeks for Geeks :- Book Allocation Problem */

#include <bits/stdc++.h>
using namespace std;

bool allocationPossible(int barrier, int n, int m, int a[])
{
    int allocStudent = 0, pages = 0;
    for (int i = 0; i < n; i++)
    {

        if (pages + a[i] > barrier)
        {
            allocStudent += 1;
            pages = a[i];
            if (pages > barrier)
                return false;
        }
        else
            pages += a[i];
    }
    if (allocStudent < m)
        return true;
    return false;
}

int findPages(int a[], int n, int m)
{
    if (m > n)
        return -1;
    int sm = 0;
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sm += a[i];
        minimum = min(minimum, a[i]);
    }
    int res = -1;
    int l = minimum, h = sm;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (allocationPossible(mid, n, m, a))
        {
            res = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}

int main()
{
    return 0;
}