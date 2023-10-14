/*-------- Medium -----------*/

/*- Number of Zero-Filled Subarrays -*/

//////// Question number 2348.

#include <bits/stdc++.h>
using namespace std;

/////// Approach - 1

/* Number of subarray that can be formed with length l is (l*(l+1))/2 */

long long zeroFilledSubarray(vector<int> &nums)
{
    long long i = 0, result = 0, n = nums.size();

    while (i < n)
    {
        long long l = 0;

        if (nums[i] == 0)
            while (i < n and nums[i] == 0)
            {
                i++;
                l++;
            }
        else
            i++;

        result += (l * (l + 1)) / 2;
    }
    return result;
}

/////// Approach - 2

/* Truly based on observations */

long long zeroFilledSubarray(vector<int> nums)
{
    long long result = 0, n = nums.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            count++;
        else
            count = 0;

        result += count;
    }
    return result;
}

int main()
{
    return 0;
}