/*-------- Medium -----------*/

/*- Stone Game II -*/

//////// Question number 1140.

#include <bits/stdc++.h>
using namespace std;

// int solve(int index, vector<int> &piles, int n, int M, int person)
// {
//     cout << "Hello" << endl;
//     if (index >= n)
//         return 0;

//     int result = (person == 1) ? -1 : INT_MAX;
//     int stones = 0;

//     for (int i = index; i <= min(2 * M, n - 1); i++)
//     {
//         if (person == 1)
//         {
//             stones += piles[i];
//             int value = solve(index + (i - index + 1), piles, n, max(M, i - index + 1), 0);
//             result = max(result, stones + value);
//         }
//         else
//             result = min(result, solve(index + (i - index + 1), piles, n, max(M, i - index + 1), 1));
//     }
//     return result;
// }

/*  */

int solve(int index, vector<int> &piles, int n, int M, int person, vector<vector<vector<int>>> &dp)
{
    if (index >= n)
        return 0;

    if (dp[person][index][M] != -1)
    {
        return dp[person][index][M];
    }

    int result = (person == 1) ? -1 : INT_MAX;
    int stones = 0;

    for (int x = 1; x <= min(2 * M, n - index); x++)
    {
        if (person == 1)
        {
            stones += piles[index + x - 1];
            int value = solve(index + x, piles, n, max(M, x), 0, dp);
            cout << stones << " " << value << endl;
            result = max(result, stones + value);
        }
        else
            result = min(result, solve(index + x, piles, n, max(M, x), 1, dp));
    }
    return dp[person][index][M] = result;
}

int stoneGameII(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
    return solve(0, piles, n, 1, 1, dp);
}

int main()
{
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << stoneGameII(piles);
    return 0;
}