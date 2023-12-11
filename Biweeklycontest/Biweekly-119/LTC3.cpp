/*--------  Medium --------*/

/*- Length of Longest Subarray With at Most K Frequency -*/

//////// Question number 100152.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int maxSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size(), window_size = INT_MIN;

    unordered_map<int, int> freq;

    int i = 0, j = 0;

    while (j < n)
    {
        // calculation part
        freq[nums[j]]++;

        if (freq[nums[j]] > k)
        {
            window_size = max(window_size, j - i);
            while (i < n and freq[nums[j]] > k)
            {
                freq[nums[i]]--;
                i++;
            }
        }
        j++;
    }
    window_size = max(window_size, j - i);

    return window_size;
}

int main()
{
    return 0;
}