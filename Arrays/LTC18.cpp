//////// Question number 268.

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();

    int sum = ((n + 1) * n) / 2;

    for (int i = 0; i < nums.size(); i++)
    {
        sum -= nums[i];
    }
    return sum;
}

/******************** Using sets ***************/
// var missingNumber = function(nums)
// {
//     const _set = new Set(nums);

//     for (let i = 0; i < nums.length + 1; i++)
//     {
//         if (!_set.has(i))
//             return i;
//     }

//     return -1;
// };

/***************** binary search approach ******************/
// int missingNumber(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int i = 0, j = nums.size() - 1, mid;
//     while (i <= j)
//     {
//         mid = (i + j) / 2;
//         if (mid == nums[mid])
//             i = mid + 1;
//         else
//             j = mid - 1;
//     }
//     return i;
// }

/******************** Bit manipulation technique ***************/
// int missingNumber(vector<int> &nums)
// {
//     int res = 0, n = nums.size();
//     for (int i = 1; i <= n; i++)
//         res ^= i;
//     for (auto x : nums)
//         res ^= x;
//     return res;
// }

int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(nums) << endl;
    return 0;
}