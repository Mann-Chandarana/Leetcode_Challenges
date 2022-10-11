/*--------Medium-----------*/
//////// Question number 75.

#include <bits/stdc++.h>
using namespace std;

/********** Using three pointer approach *************/

void sortColors(vector<int> &nums)
{
    int i = 0, j = 0, k = nums.size() - 1;

    while (j <= k)
    {
        if (nums[j] == 1)
        {
            j++;
        }
        else if (nums[j] == 0)
        {
            swap(nums[j++], nums[i++]);
        }
        else
        {
            swap(nums[j], nums[k--]);
        }
    }

    for (auto element : nums)
    {
        cout << element << " ";
    }
}

int main()
{
    vector<int> nums = {1,2,0};
    sortColors(nums);
    return 0;
}