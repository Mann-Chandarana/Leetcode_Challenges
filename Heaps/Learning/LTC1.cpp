/* Does array represent Heap */

#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (2 * i + 1 < n and a[i] <= a[2 * i + 1])
            return false;

        if (2 * i + 2 < n and a[i] <= a[2 * i + 2])
            return false;
    }
    return true;
}

int main()
{
    return 0;
}