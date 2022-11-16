/*--------Medium-----------*/

/*- 18 Sum -*/

//////// Question number 15.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    long long n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    for (int i = 0; i < n; i++)
    {
        int addition1 = target - nums[i];
        for (int j = i + 1; j < n; j++)
        {
            long long low = j + 1, high = n - 1;
            int addition2 = addition1 - nums[j];
            while (low < high)
            {
                long long sum = nums[low] + nums[high];

                if (sum > addition2)
                {
                    high--;
                }

                else if (sum < addition2)
                {
                    low++;
                }

                else
                {
                    answer.push_back({nums[i], nums[j], nums[low], nums[high]});
                    int pre_low = nums[low], pre_high = nums[high];

                    while (low < high and nums[low] == pre_low)
                    {
                        low++;
                    }
                    while (low < high and nums[high] == pre_high)
                    {
                        high--;
                    }
                    if (low >= high)
                    {
                        break;
                    }
                }
            }
            while (j + 1 < n and nums[j + 1] == nums[j])   /// eleminating duplicates
            {
                j++;
            }
        }
        while (i + 1 < n and nums[i + 1] == nums[i])    /// eleminating duplicates
        {
            i++;
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    fourSum(nums, 0);
    return 0;
}