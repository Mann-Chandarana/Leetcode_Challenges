/*--------  Medium --------*/

/*- Binary Subarrays With Sum -*/

//////// Question number 930.

#include <bits/stdc++.h>
using namespace std;

/* Optimal solution without using maps
https://leetcode.com/problems/binary-subarrays-with-sum/solutions/2866679/easy-and-detailed-sliding-window-approach-at-most-method-detailed-explanation-c-o-n/
  */

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

/* Using Hashmap */

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == goal)
            ans++;

        if (mp.find(sum - goal) != mp.end())
            ans += mp[sum - goal];

        if (mp.find(sum) != mp.end())
            mp[sum]++;
        else
            mp[sum] = 1;
    }

    return ans;
}

int main()
{
    return 0;
}