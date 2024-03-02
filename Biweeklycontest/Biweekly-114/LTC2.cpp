#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach - 1) */

int minOperations(vector<int> &nums)
{
    int n = nums.size();

    map<int, int> mp;

    for (auto &i : nums)
        mp[i]++;

    int count = 0;

    for (auto it : mp)
    {
        if (it.second < 2)
            return -1;
        count += (it.second + 2) / 3;
    }
    return count;
}

/* Approach -2) */

int minOperations(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto &i : nums)
    {
        mp[i]++;
    }
    for (auto &it : nums)
    {
        if (mp[it] == 1)
        {
            return -1;
        }
    }

    // Now check for each
    int cnt = 0;
    for (auto &i : mp)
    {
        if (i.second % 3 == 0)
        {
            cnt += (i.second / 3);
        }
        else
        {
            cnt += (i.second / 3) + 1;
        }
    }
    return cnt;
}

int main()
{
    vector<int> nums = {2, 3, 3, 2, 2, 4, 2, 3, 4};
    cout << minOperations(nums) << endl;
    return 0;
}