#include <bits/stdc++.h>
using namespace std;

int findNonMinOrMax(vector<int> &nums)
{
    int mini = *min_element(nums.begin(), nums.end());
    int maxi = *max_element(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != maxi and nums[i] != mini)
            return nums[i];
    }
    return -1;
}

int main()
{
    vector<int> nums = {2, 1, 3};
    cout << findNonMinOrMax(nums) << endl;
    return 0;
}