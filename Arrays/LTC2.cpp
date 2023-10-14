//////// Question number 1929.

#include <bits/stdc++.h>
using namespace std;

// vector<int> getConcatenation(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         nums.push_back(nums[i]);
//     }
//     return nums;
// }

vector<int> getConcatenation(vector<int> &nums)
{
    vector<int> ans(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(nums[i]);
    }
    return ans;
}

int main()
{
    return 0;
}