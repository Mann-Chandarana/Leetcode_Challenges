/*--------  Medium --------*/

/*- Minimize Maximum Pair Sum in Array -*/

//////// Question number 1877.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach -1) */

int minPairSum(vector<int> &nums)
{
    int n = nums.size();
    sort(all(nums));

    int i = 0, j = n - 1, maxSum = INT_MIN;

    while (i < j)
        maxSum = max(maxSum, nums[i++] + nums[j--]);

    return maxSum;
}

/* Approach -2) */

int minPairSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(100001, 0);

    int maxSum = INT_MIN, minNum = INT_MAX, maxNum = INT_MIN;

    for (int i = 0; i < n; i++)
        minNum = min(minNum, nums[i]), maxNum = max(maxNum, nums[i]), freq[nums[i]]++;

    int low = minNum, high = maxNum;

    while (low <= high)
    {
        if (freq[low] == 0)
            low++;
        else if (freq[high] == 0)
            high--;
        else
        {
            maxSum = max(maxSum, low + high);
            freq[low]--, freq[high]--;
        }
    }
    return maxSum;
}

int main()
{
    return 0;
}