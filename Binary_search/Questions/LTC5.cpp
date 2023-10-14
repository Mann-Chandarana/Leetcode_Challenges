/*--------  Medium --------*/

/*- Single Element in a Sorted Array -*/

//////// Question number 540.

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if ((mid % 2 == 0 and mid + 1 < n and nums[mid] == nums[mid + 1]) || (mid % 2 == 1 and mid - 1 >= 0 and nums[mid] == nums[mid - 1]))
            start = mid + 1;

        else
            end = mid;

        if (mid - 1 >= 0 and mid + 1 < n and nums[mid] != nums[mid + 1] and nums[mid] != nums[mid - 1])
            return nums[mid];
    }
    return nums[start];
}

// int singleNonDuplicate(vector<int> &nums)
// {
//     int start = 0, end = nums.size() - 1;

//     while (start < end)
//     {
//         int mid = start + (end - start) / 2;

//         if (mid % 2 == 1)
//             mid--;

//         if (nums[mid] != nums[mid + 1])
//             end = mid;

//         else
//             start = mid + 2;
//     }
//     return nums[start];
// }

int main()
{
    return 0;
}