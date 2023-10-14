//////// Question number 283.

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != 0 && nums[i] == 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
        else if (nums[i] != 0)
            i++;
    }
    return;
}

int main()
{
    vector<int> nums = {0, 0, 0, 4, 5, 0, 6, 7, 0};
    moveZeroes(nums);
    return 0;
}