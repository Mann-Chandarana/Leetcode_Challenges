/*--------  Medium --------*/

/*- Find the Duplicate Number -*/

//////// Question number 287.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int findDuplicate(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int idx = abs(nums[i]);

        if (nums[idx] < 0)
            return idx;

        nums[idx] = -nums[idx];
    }
    return n;
}

int findDuplicate(vector<int> &nums)
{
    int fast = nums[0];
    int slow = nums[0];

    fast = nums[nums[fast]];
    slow = nums[slow];

    while (fast != slow)
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    }

    fast = nums[0];

    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return fast;
}

int main()
{
    return 0;
}