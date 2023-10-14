//////// Question number 1909.

#include <bits/stdc++.h>
using namespace std;

bool canBeIncreasing(vector<int> &nums)
{
    int previous = nums[0];
    bool is_removed = false;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] <= previous)
        {
            if (is_removed)
                return false;

            is_removed = true;

            if (i == 1 || nums[i] > nums[i - 2])
                previous = nums[i];
        }
        else
            previous = nums[i];
    }
    return true;
}

int main()
{
    vector<int> nums = {1, 4, 1, 2, 3};
    if (canBeIncreasing(nums))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}