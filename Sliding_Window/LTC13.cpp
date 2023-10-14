/*-------- Medium -----------*/

/*- K Radius Subarray Averages -*/

//////// Question number 2090.

#include <bits/stdc++.h>
using namespace std;

vector<int> getAverages(vector<int> &nums, int k)
{
    int n = nums.size();

    if (k == 0)
        return nums;

    vector<int> result(n, -1);

    if (n < 2 * k + 1)
        return result;

    long long windowsum = 0;
    int left = 0, right = 2 * k;

    for (int i = left; i <= right; i++)
        windowsum += nums[i];

    int i = k;

    result[i] = (windowsum / (2 * k + 1));

    i++;
    right++;

    while (right < n)
    {
        int out_of_window = nums[left];
        int came_to_window = nums[right];

        windowsum = windowsum - out_of_window + came_to_window;

        result[i] = windowsum / (2 * k + 1);
        i++;
        right++;
        left++;
    }
    return result;
}

int main()
{
    vector<int> nums = {100000};
    getAverages(nums, 0);
    return 0;
}