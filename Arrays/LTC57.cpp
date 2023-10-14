/*- Find Pivot Index -*/

//////// Question number 724.

#include <bits/stdc++.h>
using namespace std;

/*  Space complexity O(1)  */
int pivotIndex(vector<int> &nums)
{
    int n = nums.size(), sum_left = 0, sum_right = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum_right += nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        sum_left += nums[i];

        if (sum_left == sum_right)
        {
            return i;
        }
        sum_right -= nums[i];
    }

    return -1;
}

// int pivotIndex(vector<int> &nums)
// {
//     int n = nums.size();

//     vector<int> prefix(nums.begin(), nums.end());
//     vector<int> postfix(nums.begin(), nums.end());

//     for (int i = 1; i < n; i++)
//     {
//         prefix[i] += prefix[i - 1];
//     }

//     for (int i = n - 2; i >= 0; i--)
//     {
//         postfix[i] += postfix[i + 1];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (prefix[i] == postfix[i])
//         {
//             return i;
//         }
//     }
//     return -1;
// }

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(nums) << endl;

    return 0;
}