/*--------  Medium --------*/

/*- Search in Rotated Sorted Array II -*/

//////// Question number 81.

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] == target)
            return 1;

        else if (nums[low] == nums[mid] and nums[mid] == nums[high])
            low++, high--;

        else if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] and target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (target >= nums[mid] and target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return 0;
}

int main()
{
    return 0;
}