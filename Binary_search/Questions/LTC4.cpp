/* 35. Search Insert Position */

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return end + 1;
}

int searchInsert(vector<int> nums, int target)
{
    int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    return index;
}

int main()
{
    return 0;
}