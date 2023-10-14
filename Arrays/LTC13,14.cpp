//////// Question number 1389,1528.

#include <bits/stdc++.h>
using namespace std;

/////////////////// Q) -------> 1389

// vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
// {
//     vector<int> ans;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         ans.insert(ans.begin() + index[i], nums[i]);
//     }
//     return ans;
// }

/////////////////// Q) -------> 1528

string restoreString(string s, vector<int> &indices)
{
    string ans = s;

    for (int i = 0; i < indices.size(); i++)
    {
        ans[indices[i]] = s[i];
    }
    return ans;
}

int main()
{
    
    return 0;
}