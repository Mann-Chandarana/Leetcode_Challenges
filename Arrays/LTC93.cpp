/* 896. Monotonic Array */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

bool isMonotonic(vector<int> &nums)
{
    int n = nums.size();

    if (n <= 1)
        return true;

    bool isIncreasing = false, isDecreasing = false;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] < nums[i + 1])
            isIncreasing = true;
        else if (nums[i] > nums[i + 1])
            isDecreasing = true;
    }
    return (isIncreasing && isDecreasing) ? false : true;
}

int main()
{
    return 0;
}