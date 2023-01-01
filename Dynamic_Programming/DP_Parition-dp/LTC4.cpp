/* Evaluate boolean expression to be true */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int i, int j, bool isTrue, string S, vector<vector<vector<int>>> dp)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (isTrue)
            return S[i] == 'T';

        else
            return S[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }

    int ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int left_true = solve(i, ind - 1, 1, S, dp);
        int left_false = solve(i, ind - 1, 0, S, dp);
        int right_true = solve(ind + 1, j, 1, S, dp);
        int right_false = solve(ind + 1, j, 0, S, dp);

        if (S[ind] == '&')
        {
            if (isTrue)
            {
                ways += (left_true * right_true);
            }
            else
            {
                ways += ((left_false * right_false) + (left_false * right_true) + (left_true * right_false));
            }
        }
        else if (S[ind] == '|')
        {
            if (isTrue)
            {
                ways += ((left_true * right_true) + (left_false * right_true) + (left_true * right_false));
            }
            else
            {
                ways += (left_false * right_false);
            }
        }
        else if (S[ind] == '^')
        {
            if (isTrue)
            {
                ways += ((left_true * right_false) + (left_false * right_true));
            }
            else
            {
                ways += ((left_true * right_true) + (left_false * right_false));
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int countWays(int N, string S)
{
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
    return solve(0, N - 1, 1, S, dp);
}

int main()
{
    string S = "T^F|F";
    cout << countWays(5, S);

    return 0;
}