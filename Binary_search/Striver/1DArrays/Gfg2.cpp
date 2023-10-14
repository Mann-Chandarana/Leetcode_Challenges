/* Count the occurence of the sorted array */

#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int nums[], int target, int n)
{
    int low = 0, high = n - 1, ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

int lastOccurence(int nums[], int target, int n)
{
    int low = 0, high = n - 1, ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

int count(int arr[], int n, int x)
{
    int first = firstOccurence(arr, x, n);
    int last = lastOccurence(arr, x, n);
    
    if(first==-1)
       return 0;
    return (last-first) + 1;
}

int main()
{
    return 0;
}