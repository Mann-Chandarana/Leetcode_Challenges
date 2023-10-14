//////// Question number 1.

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    multimap<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp.insert({nums[i], i});
    }

    int x = 0, y = 0;
    vector<int> answer;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = mp.find(target - nums[i]);
        if (it != mp.end() and (*it).second != i)
        {
            cout << nums[i] << " " << nums[(*it).second] << endl;
            answer.push_back(i);
            answer.push_back((*it).second);
            break;
        }
    }
    return answer;
}

/****************************Using Unordered map*************************************/
// vector<int> twoSum(vector<int> &arr, int t)
// {
//     vector<int> ans;
//     long long int n = arr.size();
//     unordered_map<int, int> mp;
//     for (long long int i = 0; i < n; i++)
//     {
//         if (mp.find(t - arr[i]) != mp.end())
//         {
//             long long temp = t - arr[i];
//             ans.emplace_back(mp[temp]);
//             ans.emplace_back(i);
//             return ans;
//         }
//         else
//             mp[arr[i]] = i;
//     }
//     return ans;
// }

int main()
{
    vector<int> nums = {2, 1, 3};
    nums = twoSum(nums, 4);
    for (auto ele : nums)
    {
        cout << ele << " ";
    }

    return 0;
}