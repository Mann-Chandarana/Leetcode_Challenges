//////// Question number 414.

#include <bits/stdc++.h>
using namespace std;

/************ Using sets *********************/
// int thirdMax(vector<int> &nums)
// {
//     int size = nums.size();
//     set<int> s1;
//     sort(nums.begin(), nums.end());
//     for (int i = size - 1; i >= 0; i--)
//     {
//         s1.insert(nums[i]);
//         if (s1.size() == 3)
//             break;
//     }
//     if (s1.size() < 3)
//         return *max_element(nums.begin(), nums.end());
//     else
//         return (*(s1.begin()));
// }

int thirdMax(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int c = 1;
    int maxi = nums[nums.size() - 1];

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] != maxi && c <= 3)
        {
            maxi = nums[i];
            c++;
            if (c == 3)
            {
                return maxi;
            }
        }
    }
    return nums[nums.size() - 1];
}

int main()
{
    vector<int> nums = {2, 2, 3, 1};
    cout << thirdMax(nums) << endl;
    return 0;
}