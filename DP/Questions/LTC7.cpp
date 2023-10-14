/*--------  Medium --------*/

/*- Champagne Tower -*/

//////// Question number 799.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/*
recurrence relation
i,j = i-1,j-1 + i-1,j
*/

/* Recursion + Memorization */

double solve(int i, int j, int poured, vector<vector<double>> &dp)
{
    if (i < 0 || j < 0 || i < j)
        return 0.0;

    if (i == 0 and j == 0)
        return dp[i][j] = poured;

    if (dp[i][j] != -1)
        return dp[i][j];

    double up_left = ((solve(i - 1, j - 1, poured, dp) - 1) / 2.0);
    double up_right = ((solve(i - 1, j, poured, dp) - 1) / 2.0);

    if (up_left < 0)
        up_left = 0.0;

    if (up_right < 0)
        up_right = 0.0;

    return dp[i][j] = up_left + up_right;
}

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> dp(query_row + 1, vector<double>(query_glass + 1, -1));
    return min(1.0, solve(query_row, query_glass, poured, dp));
}

/* Tabulation */

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> dp(query_row + 2, vector<double>(query_glass + 2, 0.0));

    dp[1][1] = poured;
    for (int i = 1; i <= query_row + 1; i++)
    {
        for (int j = 1; j <= query_glass + 1; j++)
        {
            if (i < j || (i == 1 and j == 1))
                continue;

            double up_left = (dp[i - 1][j - 1] - 1) / 2.0;
            double up_right = (dp[i - 1][j] - 1) / 2.0;

            if (up_left < 0)
                up_left = 0.0;

            if (up_right < 0)
                up_right = 0.0;

            dp[i][j] = up_left + up_right;
        }
    }
    return min(1.0, dp[query_row + 1][query_glass + 1]);
}

/* Approach -3) */

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> dp(query_row + 2, vector<double>(query_glass + 2, 0.0));

    dp[0][0] = poured;

    for (int i = 0; i <= query_row; i++)
    {
        for (int j = 0; j <= query_glass; j++)
        {
            double excess = (dp[i][j] - 1.0) / 2.0;

            if (excess > 0)
            {
                dp[i + 1][j] += excess;
                dp[i + 1][j + 1] += excess;
            }
        }
    }
    return min(1.0, dp[query_row][query_glass]);
}

/* Space Optimization */

double champagneTower(int poured, int query_row, int query_glass)
{
    double dp[query_row + 1];
    memset(dp, 0.0, sizeof(dp));
    dp[0] = poured;
    for (int row = 0; row < query_row; row++)
    {
        for (int col = row; col >= 0; col--)
        {
            double excess_half = std::max(0.0, (dp[col] - 1) / 2.0);
            dp[col + 1] += excess_half;
            dp[col] = excess_half;
        }
    }
    return min(1.0, dp[query_glass]);
}

int main()
{
    return 0;
}