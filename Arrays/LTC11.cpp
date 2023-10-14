//////// Question number 1313.

#include <bits/stdc++.h>
using namespace std;

///////-----------> Time complexity is O(N)

vector<int> decompressRLElist(vector<int> &nums)
{
    vector<int> result;
    for (int i(0); i < nums.size(); i += 2)
    {
        result.insert(result.end(), nums[i], nums[i + 1]);
    }
    return result;
}

// vector<int> decompressRLElist(vector<int> &nums)
// {
//     vector<int> ans;

//     for (int i = 0; i < nums.size(); i += 2)
//     {
//         int value = nums[i + 1];
//         for (int j = 0; j < nums[i]; j++)
//         {
//             ans.push_back(value);
//         }
//     }
//     return ans;
// }

int main()
{

    return 0;
}