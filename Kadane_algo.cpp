/* DP kadane algorithm */

#include <bits/stdc++.h>
using namespace std;

/* Using Kadane algorithm we can find the maximum subarray sum from the given array */

int maxSubArray(vector<int> &nums)
{
    int sum = 0, maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

/* Using Kadane algorithm we can also find the minimum subarray sum from the given array */

int minSubArray(vector<int> &nums)
{
    int sum = 0, mini = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        mini = min(mini, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return mini;
}

/*
 --> For finding the minimum subarray sum we can also invert the the array
means making negative value to positive and positive value to negative

and then we can find the maximum sum subarray using kadane's algorithm 

*/

int main()
{

    return 0;
}