/* 6954. Count Pairs Whose Sum is Less than Target */

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] >= target)
            break;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] < target)
                count++;
        }
    }
    return count;
}

int main()
{
    return 0;
}