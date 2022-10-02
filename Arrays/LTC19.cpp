//////// Question number 485.

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int sum = 0, maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            maxi = max(maxi, sum);
            sum = 0;
            continue;
        }

        sum += nums[i];
    }
    maxi = max(maxi, sum);
    return maxi;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}