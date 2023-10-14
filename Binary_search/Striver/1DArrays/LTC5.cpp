/*--------  Medium --------*/

/*- Find Minimum in Rotated Sorted Array -*/

//////// Question number 153.

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1, ans = INT_MAX;

    while (low <= high)
    {
        if (nums[low] < nums[high])
        {
            ans = min(ans, nums[low]);
            break;
        }
        int mid = low + (high - low) / 2;
        cout << mid << endl;

        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1};
    cout << findMin(nums) << endl;
    return 0;
}