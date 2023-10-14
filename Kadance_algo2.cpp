/*-------- Medium -----------*/

/*- Maximum Sum Circular Subarray -*/

//////// Question number 918.

#include <bits/stdc++.h>
using namespace std;

/* 
1) Simply here we find the maximum subarray from the non-circular pattern
and for circular pattern
2) We first find the subarray with the minimum sum and then subtract it from the total sum
*/

/*
For finding maximum sum subarray of the circular we can first
find the sum of the whole array and then we can substract the minmum subbarray sum.

 maximum subarray sum of circular = total_sum - minimum subarray sum
*/

int Kadane_algorithm(vector<int> nums)
{
    int n = nums.size(), sum = 0, maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int maxSubarraySumCircular(vector<int> &nums)
{
    int non_circular_sum = Kadane_algorithm(nums);

    int total_sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        total_sum += nums[i];
        nums[i] = -nums[i];
    }

    int circular_sum = total_sum + Kadane_algorithm(nums);

    return max(circular_sum,non_circular_sum);
}

int main()
{
    return 0;
}