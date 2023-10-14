/*-------- Medium -----------*/

/*- Number of Longest Increasing Subsequence -*/

//////// Question number 673.

#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size(), maxi = INT_MIN;
    vector<int> dp(n, 1), cnt(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] and dp[prev] == dp[i])
            {
                dp[i] = dp[prev] + 1;
                cnt[i] = cnt[prev];
            }
            else if (arr[i] > arr[prev] and dp[prev] + 1 == dp[i])
            {
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int nos = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            nos += cnt[i];
        }
    }
    return nos;
}

int main()
{
    vector<int> nums = {1, 5, 4, 3, 2, 6, 7, 2};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}