//////// Question number 53.

#include <bits/stdc++.h>
using namespace std;

// time complexity is O(N^2)
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0, maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

/*----------- Using Kadane's algorithm ------------------*/
// time complexity is O(N)

// int maxSubArray(vector<int> &nums)
// {
//     int sum = 0, maxi = INT_MIN;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum += nums[i];
//         maxi = max(sum, maxi);
//         if (sum < 0)
//         {
//             sum = 0;
//         }
//     }
//     return maxi;
// }

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;

    return 0;
}