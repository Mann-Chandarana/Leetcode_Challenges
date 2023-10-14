/*-------- Medium -----------*/

/*- Stone Game III -*/

//////// Question number 1406.

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memorization */

int solve(int index, vector<int> &stoneValue, int n, vector<int> dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int result = stoneValue[index] - solve(index + 1, stoneValue, n, dp);

    if (index + 1 < n)
        result = max(result, stoneValue[index] + stoneValue[index + 1] - solve(index + 2, stoneValue, n, dp));

    if (index + 2 < n)
        result = max(result, stoneValue[index] + stoneValue[index + 1] + stoneValue[index + 2] - solve(index + 3, stoneValue, n, dp));

    return dp[index] = result;
}

string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();

    vector<int> dp(n + 1, -1);
    int answer = solve(0, stoneValue, n, dp);

    if (answer > 0)
        return "Alice";

    else if (answer == 0)
        return "Tie";

    return "Bob";
}

/* Tabulation  */

string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();

    vector<int> dp(n + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        int result = stoneValue[index] - dp[index + 1];

        if (index + 1 < n)
            result = max(result, stoneValue[index] + stoneValue[index + 1] - dp[index + 2]);

        if (index + 2 < n)
            result = max(result, stoneValue[index] + stoneValue[index + 1] + stoneValue[index + 2] - dp[index + 3]);

        dp[index] = result;
    }

    int answer = dp[0];

    if (answer > 0)
        return "Alice";

    else if (answer == 0)
        return "Tie";

    return "Bob";
}

int main()
{
    return 0;
}