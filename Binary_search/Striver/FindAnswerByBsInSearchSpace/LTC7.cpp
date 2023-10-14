/*-------- Medium -----------*/

/*- Split Array Largest Sum -*/

//////// Question number 410.

#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int> &nums, int k, int mid)
{
    int sum = 0, count = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > mid)
            return false;

        if (sum + nums[i] <= mid)
            sum += nums[i];
        else
        {
            count++;
            sum = nums[i];
        }
        if (count > k)
            return false;
    }
    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();

    int low = *min_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0);

    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canSplit(nums, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    return 0;
}