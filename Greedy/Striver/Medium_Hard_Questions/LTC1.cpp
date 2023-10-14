/*-------- Medium -----------*/

/*- Jump Game -*/

//////// Question number 55.

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int reachable = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (reachable < i)
            return false;

        reachable = max(reachable, i + nums[i]);
    }
    return true;
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << canJump(nums) << endl;
    return 0;
}