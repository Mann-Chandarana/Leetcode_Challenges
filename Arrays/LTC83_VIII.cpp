/*-------- Medium -----------*/

/*- Maximum product subarray -*/

//////// Question number 152.

#include <bits/stdc++.h>
using namespace std;

/*
Here we are maintaing two things
1) first maximum multiplication upto given index 
2) second minimum multiplication upto given index

because if any negative number comes :- then on multiplication of minimum number with negative number 
                                        will gave maximum multiplication 
*/

int maxProduct(vector<int> &nums)
{
    int max_multi = nums[0], min_multi = nums[0], product = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            swap(max_multi, min_multi);
        }

        max_multi = max(nums[i], max_multi * nums[i]);
        min_multi = min(nums[i] * min_multi, nums[i]);

        product = max(product, max_multi);
    }

    return product;
}

int main()
{
    vector<int> nums = {-2, 0, -1};
    cout << maxProduct(nums) << endl;
    return 0;
}