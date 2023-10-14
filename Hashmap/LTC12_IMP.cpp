/*-------- Medium -----------*/

/*- Minimum Operations to Reduce X to Zero -*/

//////// Question number 1658.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int minOperations(vector<int> &nums, int x)
{
    int n = nums.size();

    unordered_map<int, int> mp;
    int sum = 0;

    mp[0] = -1;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        mp[sum] = i;
    }

    if (sum < x)
        return -1;

    int remaining_sum = sum - x;
    int longest_subArray = INT_MIN;

    sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        int findSum = sum - remaining_sum;

        if (mp.find(findSum) != mp.end())
        {
            int idx = mp[findSum];
            longest_subArray = max(longest_subArray, i - idx);
        }
    }

    return longest_subArray == INT_MIN ? -1 : n - longest_subArray;
}

int main()
{
    return 0;
}