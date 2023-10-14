/* 217. Contains Duplicate */

#include <bits/stdc++.h>
using namespace std;

/* Using sorting */

bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    bool flag = false;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            return true;
    }
    return flag;
}

/* Using Sets */

bool containsDuplicate(vector<int> &nums)
{
    return nums.size() > set<int>(nums.begin(), nums.end()).size();
}

/* Using Hashmap */

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (auto element : nums)
    {
        mp[element]++;
    }

    for (auto element : mp)
    {
        if (element.second > 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    return 0;
}