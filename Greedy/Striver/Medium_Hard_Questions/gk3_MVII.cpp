/* Geeks for Geeks :- Minimum Platform required for railway  */

/* Here we have to sort the array indiviually because here we only need the time where the platform is getting empty */

#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platform = 0, count = INT_MIN;
    int i = 0, j = 0;

    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
        {
            platform++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            platform--;
            j++;
        }
        count = max(count, platform);
    }
}

int main()
{
    return 0;
}