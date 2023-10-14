#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

ll f(int i, int j, int isTrue, string exp)
{
    if (i > j)
        return 0;

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';

        else
            return exp[i] == 'F';
    }

    ll ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        ll lT = f(i, ind - 1, 1, exp);
        ll lF = f(i, ind - 1, 0, exp);
        ll rT = f(ind + 1, j, 1, exp);
        ll rF = f(ind + 1, j, 0, exp);

        if (exp[ind] == '&')
        {
            if (isTrue)
                ways += lT * rT;

            else
                ways = ways + (lF * rT) + (lT * rF) * (lF * rF);
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways = ways + (lF * rT) + (lT * rF) + (lT * rT);
            else
                ways += (lF * rF);
        }
        else if (exp[ind] == '^')
        {
            if (isTrue)
                ways = ways + (lF * rT) + (lT * rF);
            else
                ways = ways + (lT * rT) + (lF * rF);
        }
    }
    return dp[i][j][isTrue] = ways;
}

int main()
{
    return 0;
}