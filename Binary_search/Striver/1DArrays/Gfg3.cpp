/* find K Rotation */

#include <bits/stdc++.h>
using namespace std;

/* Find the index of the minimum value in the rotated array */

int findKRotation(int arr[], int n)
{
    int low = 0, high = n - 1;
    int mini = INT_MAX, ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < mini)
            {
                ans = low;
                mini = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < mini)
            {
                ans = mid;
                mini = arr[mid];
            }
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}