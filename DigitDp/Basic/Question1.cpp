/* https://www.spoj.com/problems/GONE/ */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
total digit = 8
maximum sum = 72
tight = 0 or 1
*/

ll dp[10][80][2];
ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

bool check(ll sum)
{
    for (auto &i : prime)
    {
        if (i == sum)
            return true;
    }
    return false;
}

ll solve(string str, ll pos = 0, ll sum = 0, int tight = 1)
{
    if (pos == str.length())
    {
        if (check(sum))
            return 1;
        else
            return 0;
    }
    else if (dp[pos][sum][tight] != -1)
        return dp[pos][sum][tight];

    else if (tight == 1)
    {
        ll res = 0;
        for (ll i = 0; i <= str[pos] - '0'; i++)
        {
            if (i == (str[pos] - '0'))
                res += solve(str, pos + 1, sum + i, 1);

            else
                res += solve(str, pos + 1, sum + i, 0);
        }
        dp[pos][sum][tight] = res;
        return res;
    }
    else
    {
        ll res = 0;
        for (ll i = 0; i <= 9; i++)
            res += solve(str, pos + 1, sum + i, 0);

        dp[pos][sum][tight] = res;
        return res;
    }
}

int main()
{
    ll c;
    cin >> c;

    while (c--)
    {
        ll l, r;
        cin >> l >> r;
        l = l - 1;
        string a = to_string(l);
        string b = to_string(r);

        memset(dp, -1, sizeof(dp));
        ll ans1 = solve(b);
        memset(dp, -1, sizeof(dp));
        ll ans2 = solve(a);

        cout << ans1 - ans2 << endl;
    }

    return 0;
}