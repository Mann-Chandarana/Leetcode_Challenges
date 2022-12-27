/*-------- Medium -----------*/

/*- Jump Game -*/

//////// Question number 55.

#include <bits/stdc++.h>
using namespace std;

/* Using recursion */

// bool solve(vector<int> nums, int idx)
// {
//     if (idx == nums.size() - 1)
//     {
//         return true;
//     }
//     if (idx >= nums.size() || nums[idx] == 0)
//     {
//         return false;
//     }
//     bool jump = false;
//     for (int i = 1; i <= nums[idx]; i++)
//     {
//         jump = (jump || solve(nums, (idx + i)));
//     }

//     return jump;
// }

// bool canJump(vector<int> &nums)
// {
//     int n = nums.size() - 1;
//     return solve(nums, 0);
// }

// /* Using memorization */

// bool solve(vector<int> nums, int idx, vector<int> dp)
// {
//     if (idx == nums.size() - 1)
//     {
//         return true;
//     }
//     if (idx >= nums.size() || nums[idx] == 0)
//     {
//         return false;
//     }
//     if (dp[idx] != -1)
//     {
//         return dp[idx];
//     }

//     bool jump = false;
//     for (int i = 1; i <= nums[idx]; i++)
//     {
//         if (solve(nums, (idx + i), dp))
//         {
//             return dp[idx] = true;
//         }
//     }

//     return dp[idx] = false;
// }

// bool canJump(vector<int> &nums)
// {
//     int n = nums.size() - 1;
//     vector<int> dp(n, -1);
//     return solve(nums, 0, dp);
// }

// /* Using space optimization */

// bool canJump(vector<int> &nums)
// {
//     int n = nums.size() - 1;
//     vector<int> dp(n + 1, 0);

//     dp[n] = true;

//     for (int idx = n - 1; idx >= 0; idx--)
//     {
//         for (int i = 1; i <= nums[idx]; i++)
//         {
//             if (idx + i <= n and dp[idx + i])
//             {
//                 dp[idx] = true;
//                 break;
//             }
//         }
//     }
//     return dp[0];
// }

/* Greedy */

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int reachable = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > reachable)
        {
            return false;
        }
        reachable = max(reachable, i + nums[i]);
        cout<<reachable<<endl;
    }
    return true;
}

int main()
{
    vector<int> jumps = {2, 3, 1, 1, 4};
    cout << canJump(jumps) << endl;
    return 0;
}