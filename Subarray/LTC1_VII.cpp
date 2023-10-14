/*--------  Medium --------*/

/*- Subarray Sums Divisible by K -*/

//////// Question number 974.

#include <bits/stdc++.h>
using namespace std;

/* O(N) Complexity */

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();

    int sum = 0, count = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    for (auto element : nums)
    {
        sum += element;

        int remi = sum % k;
        if (remi < 0)
            remi += k;

        if (mp.find(remi) != mp.end())
            count += mp[remi];

        mp[remi]++;
    }

    return count;
}

/* O(N^2) Complexity */

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> prefix_sum(n);
    prefix_sum[0] = nums[0];

    for (int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + nums[i];

    int count = 0;

    for (auto element : prefix_sum)
        cout << element << " ";

    cout << endl;

    int previous = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int value = prefix_sum[j] - previous;
            if (value % k == 0)
            {
                count++;
            }
        }
        previous = prefix_sum[i];
    }

    return count;
}

int main()
{
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    cout << subarraysDivByK(nums, 5) << endl;
    return 0;
}