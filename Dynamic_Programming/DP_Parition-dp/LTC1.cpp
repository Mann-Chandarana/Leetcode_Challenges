/* MCM using dp :- geeks for geeks*/

#include <bits/stdc++.h>
using namespace std;

/* Using Recursion */

int solve(int arr[], int i, int j, vector<vector<int>> dp)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int ans = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(int N, int arr[])
{
    int i = 1, j = N - 1;
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(arr, i, j, dp);
}

/* Using tabulation */

int matrixMultiplication(int N, int arr[])
{
    int i = 1, j = N - 1;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i+1; j < N; j++)
        {
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int ans = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    cout << matrixMultiplication(5, arr);
    return 0;
}