//////// Question number 189.

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    ///// if k is greater than length of the array
    int len = nums.size();
    k %= len;
    if (k == 0)
    {
        return;
    }

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    return 0;
}