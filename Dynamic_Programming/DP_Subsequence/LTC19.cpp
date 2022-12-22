/* No of subset with sum equals to k :- geeks for geeks */

#include <bits/stdc++.h>
using namespace std;

int findWays(int num[], int tar,int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));

    dp[0][0] = 1;

    for (int j = 1; j <= tar; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            if (num[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][tar];
}

int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return findWays(arr, sum,n);
}

int main()
{
    int arr[] = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    cout << perfectSum(arr, 10, 31) << endl;
    return 0;
}