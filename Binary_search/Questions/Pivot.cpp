#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int pivot(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (mid - 1 >= 0 and mid + 1 < n and nums[mid - 1] < nums[mid] and nums[mid] > nums[mid + 1])
            return mid + 1;

        else if (nums[low] < nums[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return -1;
}

int main()
{
    return 0;
}