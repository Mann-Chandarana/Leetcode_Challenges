/** Rod cutting :- geeks for geeks **/

// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rod-cutting0840

#include <bits/stdc++.h>
using namespace std;

/* Using Memorization */

int solve(int price[], int idx, int N, vector<vector<int>> dp)
{
    if (idx == 0)
    {
        return N * price[0];
    }

    if (dp[idx][N] != -1)
    {
        return dp[idx][N];
    }

    int not_taken = 0 + solve(price, idx - 1, N, dp), taken = -1e8;
    if (N - (idx + 1) >= 0)
    {
        taken = price[idx] + solve(price, idx, N - (idx + 1), dp);
    }
    return dp[idx][N] = max(taken, not_taken);
}

int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(price, n - 1, n, dp);
}

/* Using Tabulation */

int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int not_taken = 0 + dp[i - 1][j], taken = -1e8;
            if (j - (i + 1) >= 0)
            {
                taken = price[i] + dp[i][j - (i + 1)];
            }
            dp[i][j] = max(taken, not_taken);
        }
    }
    return dp[n - 1][n];
}

/* Using Space optimization */

int cutRod(int price[], int n)
{
    vector<int>prev(n + 1, 0),curr(n+1,0);

    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int not_taken = 0 + prev[j], taken = -1e8;
            if (j - (i + 1) >= 0)
            {
                taken = price[i] + curr[j - (i + 1)];
            }
            curr[j] = max(taken, not_taken);
        }
        prev = curr;
    }
    return prev[n];
}

/* Using More Space optimization */

int cutRod(int price[], int n)
{
    vector<int>curr(n+1,0);

    for (int i = 0; i <= n; i++)
    {
        curr[i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int not_taken = 0 + curr[j], taken = -1e8;
            if (j - (i + 1) >= 0)
            {
                taken = price[i] + curr[j - (i + 1)];
            }
            curr[j] = max(taken, not_taken);
        }
    }
    return curr[n];
}

int main()
{
    int price[] = {2, 5, 7, 8, 10};
    cout << cutRod(price, 5) << endl;
    return 0;
}