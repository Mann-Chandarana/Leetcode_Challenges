/*- Contains duplicate 2 -*/

//////// Question number 219.

#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k)
        {
            st.erase(nums[i - k - 1]);
        }
        if (!st.insert(nums[i]).second)
        {
            return true;
        }
    }
    return false;
}

// bool containsNearbyDuplicate(vector<int> &nums, int k)
// {
//     unordered_map<int, int> mp;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (mp.count(nums[i]))
//         {
//             int difference = abs(mp[nums[i]] - i);
//             if (difference <= k)
//             {
//                 return true;
//             }
//         }
//         mp[nums[i]] = i;
//     }
//     return false;
// }

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    cout << containsNearbyDuplicate(nums, 2) << endl;
    return 0;
}