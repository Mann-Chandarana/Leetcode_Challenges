/*-------- Medium -----------*/

/*- Capacity To Ship Packages Within D Days -*/

//////// Question number 1011.

#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int arr[], int mid, int D, int N)
{
    long long int sum = 0, day = 1;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }

        sum += arr[i];
        if (sum > mid)
        {
            day++;
            sum = arr[i];
        }
        if (day > D)
            return false;
    }

    return true;
}

int leastWeightCapacity(int arr[], int N, int D)
{
    int low = 0, high = 1e8;
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isFeasible(arr, mid, D, N))
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
    int arr[] = {9, 8, 10};
    cout << leastWeightCapacity(arr, 3, 3);
    return 0;
}