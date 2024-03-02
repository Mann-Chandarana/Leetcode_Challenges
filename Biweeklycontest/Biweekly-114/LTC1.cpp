/* 8038. Minimum Operations to Collect Elements */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int minOperations(vector<int> &nums, int k)
{
    int n = nums.size();
    ll sum = ((k + 1) * (1LL) * k) / 2;
    int count = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        count++;
        if (nums[i] <= k)
            sum -= nums[i];

        if (sum == 0)
            return count;
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2};
    cout << minOperations(nums, 1) << endl;
    return 0;
}