#include <bits/stdc++.h>
using namespace std;

/* Using Recurison */

int f(int i, int j, vector<vector<int>> &triangle, int n)
{
    if (i == n - 1)
        return triangle[n - 1][j];

    int d = triangle[i][j] + f(i + 1, j, triangle, n);
    int dg = triangle[i][j] + f(i + 1, j + 1, triangle, n);

    return min(d, dg);
}

/* Using Memorization */

int f(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[n - 1][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int d = triangle[i][j] + f(i + 1, j, triangle, n);
    int dg = triangle[i][j] + f(i + 1, j + 1, triangle, n);

    return dp[i][j] = min(d, dg);
}

/* Using Tabulation */

int f(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
        return triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = triangle[i][j] + dp[i + 1][j];
            int dg = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(d, dg);
        }
    }
    return dp[0][0];
}

/* Using Space Optimization */

int f(vector<vector<int>> &triangle, int n)
{
    vector<int> next(n, 0), curr(n, 0);

    for (int j = 0; j < n; j++)
        return triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = triangle[i][j] + next[j];
            int dg = triangle[i][j] + next[j + 1];
            curr[j] = min(d, dg);
        }
        next = curr;
    }
    return next[0];
}

int main()
{
    return 0;
}