#include <bits/stdc++.h>
using namespace std;

/* Using Recursion and Memorization */

int r, c;
vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

int f(int i, int j1, int j2, vector<vector<int>> &matrix, int n, int m)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;

    if (i == n - 1)
    {
        if (j1 == j2)
            return matrix[i][j1];
        else
            return matrix[i][j1] + matrix[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e8;

    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (dj1 == dj2)
                value = matrix[i][j1];

            else
                value = matrix[i][j1] + matrix[i][j2];

            value += f(i + 1, j1 + dj1, j2 + dj2, matrix, n, m);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

/* Tabulation */

int f(vector<vector<int>> &matrix, int n, int m)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = matrix[n - 1][j1];

            else
                dp[n - 1][j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = matrix[i][j1];

                        else
                            value = matrix[i][j1] + matrix[i][j2];

                        if (j1 + dj1 >= 0 and j1 + dj1 < m and j2 + dj2 >= 0 and j2 + dj2 < m)
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
    /*
    1) Elis and bob start at row number 0
    2) Elis starts at column number 0
    3) bob starts at column number m-1
    so thatswhy we are returing dp[0][0][m-1]
    */
}

/* Space Optimization */

int f(vector<vector<int>> &matrix, int n, int m)
{
    vector<vector<int>> front(c, vector<int>(c, 0));
    vector<vector<int>> curr(c, vector<int>(c, 0));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = matrix[n - 1][j1];

            else
                front[j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = matrix[i][j1];

                        else
                            value = matrix[i][j1] + matrix[i][j2];

                        if (j1 + dj1 >= 0 and j1 + dj1 < m and j2 + dj2 >= 0 and j2 + dj2 < m)
                            value += front[j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][m - 1];
    /*
    1) Elis and bob start at row number 0
    2) Elis starts at column number 0
    3) bob starts at column number m-1
    so thatswhy we are returing dp[0][0][m-1]
    */
}

int main()
{
    return 0;
}