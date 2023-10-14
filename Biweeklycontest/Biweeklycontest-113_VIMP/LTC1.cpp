/* 8039. Minimum Right Shifts to Sort the Array */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int minimumRightShifts(vector<int> &nums)
{
    int n = nums.size(), index = INT_MAX;
    bool canRotate = false;

    for (int i = 1; i < n; i++)
    {
        if (i + 1 < n and (nums[i - 1] > nums[i]) and (nums[i - 1] < nums[i + 1]))
            return -1;

        if (nums[i - 1] > nums[i])
        {
            if (canRotate)
                return -1;
            index = i;
            canRotate = true;
        }
    }

    return (index == INT_MAX ? 0 : n - index);
}

int main()
{
    vector<int> nums = {72, 13, 21, 35, 52};
    cout << minimumRightShifts(nums) << endl;
    return 0;
}