// https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/?purpose=login&source=problem-page&update=google

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
pos = 10
tight = 0 or 1
flag = 0 or 1
 -- flag = 0 digit three is absent
 -- flag = 1 digit three is present
*/

ll dp[11][2][2];

ll go(string str, ll pos = 0, ll tight = 1, ll flag = 0)
{
    if (pos == str.length())
    {
        if (flag == 1)
            return 1;
        else
            return 0;
    }

    else if (dp[pos][tight][flag] != -1)
        return dp[pos][tight][flag];

    else if (tight == 1)
    {
        ll res = 0;
        for (ll i = 0; i <= (str[pos] - '0'); i++)
        {
            ll flg = flag;

            if (i == 3)
                flg = 1;

            if (i == (str[pos] - '0'))
                res += go(str, pos + 1, 1, flg);

            else
                res += go(str, pos + 1, 0, flg);
        }

        return dp[pos][tight][flag] = res;
    }
    else
    {
        ll res = 0;
        for (ll i = 0; i <= 9; i++)
        {
            ll flg = flag;
            if (i == 3)
                flg = true;

            res += go(str, pos + 1, 0, flg);
        }
        return dp[pos][tight][flag] = res;
    }
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        string str = to_string(n);
        memset(dp, -1, sizeof(dp));
        cout << n - go(str) << endl;
    }

    return 0;
}