/* Partition with Given Difference :- geeks for geeks */

#include <bits/stdc++.h>
using namespace std;

int m = 1e9 + 7;

int findWays(vector<int> &num, int tar,int n)
{
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }

    if (num[0] != 0 && num[0] <= tar)
    {
        dp[0][num[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notTaken = (dp[ind - 1][target])%m;

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken%m + taken%m);
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }
    if (total_sum - d < 0 || (total_sum - d) % 2 == 1)
    {
        return 0;
    }

    return (findWays(arr, ((total_sum - d) / 2), n))%m;
}

int main()
{
    vector<int> arr = {1, 1, 1, 1};
    cout << countPartitions(4, 0, arr) << endl;
    return 0;
}