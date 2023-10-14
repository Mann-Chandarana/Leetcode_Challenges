/*-------- Medium -----------*/

/*- Find First and Last Position of Element in Sorted Array -*/

//////// Question number 34.

#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &nums, int &target)
{
    int low = 0, high = nums.size() - 1, ans = -1;

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

int lastOccurence(vector<int> &nums, int &target)
{
    int low = 0, high = nums.size() - 1, ans = -1;

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

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = firstOccurence(nums, target);
    int second = lastOccurence(nums, target);

    return {first, second};
}

int main()
{
    return 0;
}