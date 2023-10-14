/*--------  Medium --------*/

/*- Count Number of Nice Subarrays -*/

//////// Question number 1248.


/* Use the concept of binary subarray with sum k */

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int i = 0, j = 0, ans = 0, sum = 0;

    while (j < nums.size())
    {
        sum += nums[j];

        while (sum > goal)
        {
            sum -= nums[i];
            i++;
        }
        ans += (j - i + 1);

        j++;
    }
    return ans;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return solution(nums, goal) - solution(nums, goal - 1);
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 != 0)
            nums[i] = 1;
        else
            nums[i] = 0;
    }
    return numSubarraysWithSum(nums, k);
}

int main()
{
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    cout << numberOfSubarrays(nums, 2) << endl;
    return 0;
}