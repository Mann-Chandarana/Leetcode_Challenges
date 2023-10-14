/*--------  Medium --------*/

/*- Smallest Missing Non-negative Integer After Operations -*/

//////// Question number 2598.

#include <bits/stdc++.h>
using namespace std;

int findSmallestInteger(vector<int> &nums, int value)
{
    unordered_map<int, int> modulocenter;

    for (auto element : nums)
    {
        modulocenter[((element % value) + value) % value] += 1;
    }

    for (int i = 0; i <= nums.size(); i++)
    {
        if (!modulocenter.count(i))
        {
            int rem = i % value;
            if (modulocenter.count(rem) and modulocenter[rem] > 1)
                modulocenter[rem] -= 1;
            else
                return i;
        }
    }
    return 0;
}

int main()
{
    vector<int> nums = {1, -10, 7, 13, 6, 8};
    cout << findSmallestInteger(nums, 5) << endl;
    return 0;
}