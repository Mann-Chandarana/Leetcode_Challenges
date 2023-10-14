//////// Question number 1920.

#include <bits/stdc++.h>
using namespace std;

/* a=a+(b%n)*n 
a=a%n
b=a/n
------> Time complexity O(N)
------> Space complexity O(1)
*/

vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] + (n * (nums[nums[i]] % n));
        ////// Important approach to learn
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] /= n;
    }
    return nums;
}

// vector<int> buildArray(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans(n);
//     for (int i = 0; i < n; i++)
//     {
//         ans[i] = nums[nums[i]];
//     }
//     return ans;
// }

int main()
{

    return 0;
}