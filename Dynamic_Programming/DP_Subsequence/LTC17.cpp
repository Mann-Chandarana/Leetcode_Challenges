/*-------- Medium -----------*/

/*- Partition Equal Subset Sum -*/

//////// Question number 416.

/* See the LTC16. solution */

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<bool> curr(sum + 1, false), prev(sum + 1, false);

    for (int i = 0; i < n; i++)
    {
        prev[0] = true;
    }
    if (arr[0] <= sum)
    {
        prev[arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool pick = false;
            if (arr[i] <= j)
            {
                pick = prev[j - arr[i]];
            }
            bool non_pick = prev[j];
            curr[j] = (pick || non_pick);
        }
        prev = curr;
    }

    return prev[sum];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto element : nums)
    {
        sum += element;
    }
    return ((sum % 2 == 0) ? solve(nums, (sum / 2)) : false);
}

int main()
{
    return 0;
}