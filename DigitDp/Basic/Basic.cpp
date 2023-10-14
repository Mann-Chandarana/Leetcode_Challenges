#include <bits/stdc++.h>
using namespace std;

/*
Restricted - [0..lmt]
UnRestricted - [0..9]

1) pos = 20 digits
2) tight = 2
3) sum = 9*20
*/

int dp[20][2][180];

int solve(string &digit, int pos, int tight, int sum)
{
    if (pos == digit.size())
        return sum;

    else if (dp[pos][tight][sum] != -1)
        return dp[pos][tight][sum];

    else if (tight == 1)
    {
        for (int i = 0; i <= digit[pos]-'0'; i++)
        {
            if (i == digit[pos]-'0')
                return dp[pos][tight][sum] = solve(digit, pos + 1, 1, sum + i);
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
            return dp[pos][tight][sum] = solve(digit, pos + 1, 0, sum + i);
    }
}

int main()
{
    return 0;
}