/*--------Medium-----------*/

/*- Containuous subarray sum -*/

//////// Question number 523.

#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    if (nums.size() < 2)
    {
        return false;
    }

    int prefix_sum = 0, start = 0, end = 0;

    unordered_map<int, int> mp;

    mp[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        prefix_sum += nums[i];

        if (k > 0)
        {
            prefix_sum %= k;
        }

        if (mp.find(prefix_sum) != mp.end())
        {
            if (i - mp[prefix_sum] > 1)
            {
                return true;
            }
        }
        else
        {
            mp[prefix_sum] = i;
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {23, 2, 4, 6, 6};
    cout << checkSubarraySum(nums, 7) << endl;
    return 0;
}