/*--------Medium-----------*/

/*- Triangle -*/

//////// Question number 120.

#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int solve(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> dp)
{
    if (dp[i][i] != -1)
    {
        return dp[i][j];
    }
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }

    int down = triangle[i][j] + solve(triangle, i + 1, j, dp);
    int diagonal = triangle[i][j] + solve(triangle, i + 1, j + 1, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(triangle, 0, 0, dp);
}

/** Using tabulation technique **/

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<int> curr(n, 0), front(n, 0);

    for (int i = 0; i < triangle[n - 1].size(); i++)
    {
        front[i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];

            curr[j] = min(down, diagonal);
        }
        front = curr;
    }

    return front[0];
}

int main()
{
    return 0;
}