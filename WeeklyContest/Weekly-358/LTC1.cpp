/* 2815. Max Pair Sum in an Array */

#include <bits/stdc++.h>
using namespace std;

/* Upsolve Solution */

int maxSum(vector<int> &nums)
{
    int res = -1, max_num[10] = {};

    for (auto num : nums)
    {
        int max_d = 0;

        for (int v = num; v; v /= 10)
            max_d = max(max_d, v % 10);

        if (max_num[max_d])
            res = max(res, max_num[max_d] + num);

        max_num[max_d] = max(max_num[max_d], num);
    }
    return res;
}

/* Solution -1 */

int maxSum(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    long long sum = 0, maxi_sum = LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        string value = to_string(nums[i]);
        int maxi = INT_MIN;
        for (int i = 0; i < value.size(); i++)
            maxi = max(maxi, value[i] - '0');

        mp[maxi].push_back(nums[i]);
    }
    for (auto i : mp)
    {
        if (mp[i.first].size() > 1)
        {
            sort(mp[i.first].begin(), mp[i.first].end(), greater<int>());
            sum = mp[i.first][0] + mp[i.first][1];
            maxi_sum = max(sum, maxi_sum);
        }
    }

    return maxi_sum == LONG_MIN ? -1 : maxi_sum;
}

int main()
{
    vector<int> nums = {68, 8, 100, 84, 80, 14, 88};
    cout << maxSum(nums) << endl;
    return 0;
}