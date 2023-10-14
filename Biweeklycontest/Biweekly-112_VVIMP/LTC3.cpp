/*--------  Medium --------*/

/*- Maximum Sum of Almost Unique Subarray -*/

//////// Question number 2841.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* General Format of sliding window */

long long maxSum(vector<int> &nums, int m, int k)
{
    unordered_map<int, int> mp;
    ll sum = 0, max_sum = 0, n = nums.size();

    int i = 0, j = 0;

    while (j < n)
    {
        sum += nums[j];
        mp[nums[j]]++;

        /// Shrinking the window
        if ((j - i + 1) > k)
        {
            mp[nums[i]]--;
            sum -= nums[i];

            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
            i++;
        }

        /// Window hits
        if ((j - i + 1) == k)
        {
            if (mp.size() >= m)
                max_sum = max(sum, max_sum);
        }

                j++;
    }

    return max_sum;
}

/* Simple Sliding window */

long long maxSum(vector<int> &nums, int m, int k)
{
    unordered_map<int, int> mp;
    ll sum = 0, max_sum = 0, n = nums.size();

    for (int i = 0; i < k; i++)
    {
        mp[nums[i]]++;
        sum += nums[i];
    }
    if (mp.size() >= m)
        max_sum = max(sum, max_sum);

    for (int i = k; i < n; i++)
    {
        // removing first element
        mp[nums[i - k]]--;
        if (mp[nums[i - k]] == 0)
            mp.erase(nums[i - k]);
        sum -= nums[i - k];

        // adding new element in the window
        mp[nums[i]]++;
        sum += nums[i];

        if (mp.size() >= m)
            max_sum = max(sum, max_sum);
    }
    if (mp.size() >= m)
        max_sum = max(sum, max_sum);
    return max_sum;
}

int main()
{
    vector<int> nums = {5, 9, 9, 2, 4, 5, 4};
    cout << maxSum(nums, 1, 3) << endl;
    return 0;
}